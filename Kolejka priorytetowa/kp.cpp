/*
    AUTOR: RAFAL ROZYCKI 226367
    SRODA 12:00

    ZAD 1

    Program jest implementacja kolejki priorytetowej.
    Operacje sa takie same jak dla zwyklej kolejki z wyjatkiem dodawania.
    Dodajac element przekazujemy klucz oraz element, ktory ma byc przechowany
    Na etapie wstawiania do kolejki najmniejsze priorytety ida na sam poczatek kolejki.

    Wstawianie elementow jest realizowane w czasie liniowym, a usuwanie w czasie stalym.

    W programie mamy menu, ktore pozwala nam przetestowac wstawianie i usuwanie elementow.
*/


#include <iostream>

using namespace std;

/*------------------------------*/

template<typename T>
class Element
{
public:
    Element<T> *next;
    int key;
    T data;
    Element();
};

template<typename T>
Element<T>::Element()
{
    next=nullptr;
}



/*------------------------------*/

template<typename T>
class PQueue
{
    Element<T> *head;
    Element<T> *tail;
    //int s; // rozmiar
public:
    void    insertElement(int k, T v);
    void    removeMin();
    bool    isEmpty();
    int     Size();
    void    display();

    PQueue();

};

template<typename T>
PQueue<T>::PQueue()
{
    head = nullptr;
    tail = nullptr;
}

/*
    Metoda insertElement przyjmuje klucz typu int oraz element dowolnego typu.
    Jezeli klucz jest wiekszy od klucza pierwszego elementu to idziemy dalej, az
    dojdziemy do miejsca kiedy klucz jest mniejszy od pewnego elementu

*/
template<typename T>
void PQueue<T>::insertElement(int k, T v)
{
    Element<T> *newE  = new Element<T>;


    newE->key = k;
    newE->data = v;

    if(head==nullptr)
    {
        head = tail = newE;
    }
    else
    {
        if(head->key < k)
        {
            Element<T> *temp = head;
            while((temp->next!=nullptr) && ((temp->next)->key <= k))
            {
                temp = temp->next;
            }

            newE->next = temp->next;
            temp->next = newE;
            if(newE->next == nullptr) tail = newE;
        }
        else
        {
            newE->next = head;
            head = newE;
        }

    }

}

/*
    Metoda removeMin usuwa element o najmniejszym priorytecie, ktory
    zawsze jest pierwszym elementem.
*/
template<typename T>
void PQueue<T>::removeMin()
{
    Element<T> *old = head;

    if(head==nullptr)
    {
        cout << "\nKolejka pusta, nie mozna nic usunac";
    }
    else
    {
        //old->next = head;
        head = old->next;
        delete old;
    }
}

/*
    Funkcja display odpowiada za wyswietlanie kolejki priorytetowej
*/
template<typename T>
void PQueue<T>::display()
{
    Element<T> *temp = head;

    if(temp==nullptr)
    {
        cout << "\nPusto";
    }
    else
    {
        while(temp)
        {
            cout << "\nKlucz: " << temp->key << " Dane: " << temp->data;
            temp = temp->next;
        }
    }
}


/*

*/
int main()
{
    PQueue<string> Q;
    int key=0;
    string value;
    int choice=0;
    bool End=false;

    cout << "\tMENU";
    cout << "\n1. Wyswietl kolejke priorytetowa.";
    cout << "\n2. Dodaj element do kolejki priorytetowej.";
    cout << "\n3. Usun element z kolejki.";
    cout << "\n4. Wyjscie.";

    while(!End)
    {
        cout << "\nTwoj wybor: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                Q.display();
                break;
            }
        case 2:
            {
                cout << "\nKlucz: ";
                cin >> key;
                cout << "\nWartosc: ";
                cin >> value;
                Q.insertElement(key,value);
                break;
            }
        case 3:
            {
                Q.removeMin();
                break;
            }
        case 4:
            {
                End = true;
                break;
            }

        }
    }
    return 0;
}
