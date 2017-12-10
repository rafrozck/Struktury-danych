/*
    Autor: Rafal Rozycki 226367

    Program stanowi implementacje deque, czyli kolejki z dwoma koncami
    Funkcje deque:
    - zwracanie pierwszego i ostatniego elementu
    - zwracanie rozmiaru
    - usuwanie z przodu i z tylu
    - dodawanie z przodu i z tylu
    - wyswietlanie
    - usuwanie wszystkich elementow

    Deque wypelniamy dowolnymi elementami, program posiada menu uzytkownika
*/

#include <iostream>

using namespace std;

template<typename T>
class Element
{
public:
    T dane;
    Element<T> *nastepny;
    Element();
};

template<typename T>
Element<T>::Element()
{
    nastepny=nullptr;
}

////////////////////////////

template<typename T>
class Deque
{
    Element<T> *glowa;
public:

    Deque();




    int rozmiar();
    bool czyPusty();
    T& pierwszy();
    T& ostatni();
    void dodaj_przod(T el);
    void dodaj_tyl(T el);
    void usun_przod();
    void usun_tyl();
    void wyswietl();
    void usun_wszystkie();
    //bool jestPal(Deque<T> d);
};

template<typename T>
Deque<T>::Deque()
{
    glowa=nullptr;
}

template<typename T>
T& Deque<T>::pierwszy()
{
    Element<T> *temp = glowa;
    return temp->dane;
}

template<typename T>
T& Deque<T>::ostatni()
{
    Element<T> *temp = glowa;
    while(temp->nastepny)
    {
        temp = temp->nastepny;
    }
    return temp->dane;
}

//Funkcja zwracajaca rozmiar deque'a
template<typename T>
int Deque<T>::rozmiar()
{
    Element<T> *temp = glowa;
    int n=1;

    if(glowa==nullptr)
    {
        return 0;
    }
    else
    {
        while(temp->nastepny)
        {
            temp = temp->nastepny;
            n++;
        }
        return n;
    }
}

template<typename T>
void Deque<T>::dodaj_przod(T el)
{
    Element<T> *nowy = new Element<T>;

    nowy->dane = el;
    nowy->nastepny = glowa;
    glowa=nowy;
}


template<typename T>
void Deque<T>::dodaj_tyl(T el)
{
    Element<T> *nowy = new Element<T>; //Tworzymy nowy element(wezel)

    nowy->dane = el; //zapis danych

    if(glowa==nullptr) //Sprawdzamy czy to pierwszy element listy
    {
        //Nowy element teraz jest poczatkiem listy
        glowa=nowy;
    }
    else
    {
        // zmienna pomocnicza
        Element<T> *temp = glowa;

        // jesli nie, idziemy na koniec
        while(temp->nastepny)
        {
            // znajdujemy wskaznik na ostatni element
            temp = temp->nastepny;
        }
        temp->nastepny = nowy; // ostatni element wskazuje na nowy
        nowy->nastepny = nullptr; //

    }
}

template<typename T>
void Deque<T>::usun_przod()
{
    Element<T> *stary = glowa;

    if(glowa==nullptr)
    {
        cout << "\nDeque jest pusty.";
    }
    else
    {
        glowa = stary->nastepny;
        delete stary;
    }
}

template<typename T>
void Deque<T>::usun_tyl()
{
    Element<T> *temp = glowa;

    if(glowa==nullptr)
    {
        cout << "\nDeque jest pusty.";
    }
    else
    {
        if(temp->nastepny==nullptr)
        {
            delete(temp);
            glowa=nullptr;
        }
        else
        {
            while(temp->nastepny)
            {

                if(temp->nastepny->nastepny==nullptr)
                {
                    delete(temp->nastepny);
                    temp->nastepny=nullptr;
                    break;
                }
                else
                {
                    temp = temp->nastepny;
                }
            }
        }
    }
}

template<typename T>
void Deque<T>::wyswietl()
{
    // wskaznik na pierwszy element
    Element<T> *temp = glowa;

    if(temp==nullptr)
    {
        cout << "\nDeque jest pusty.";
    }
    else
    {
        while(temp)
        {
            cout << "\n" << temp->dane ;
            temp = temp->nastepny;
        }
    }
}

template<typename T>
void Deque<T>::usun_wszystkie()
{

    while(glowa!=nullptr)
    {
        Element<T> *temp = glowa;
        glowa = temp->nastepny;
        delete(temp);
    }
}

int main()
{

    Deque<char> d;
    char znak;
    int wybor=0;
    bool zakoncz=false;

    cout << "\tMENU";
    cout << "\n1. Wyswietl deque.";
    cout << "\n2. Dodaj element z przodu deque'a.";
    cout << "\n3. Dodaj element z tylu deque'a.";
    cout << "\n4. Usun element z przodu deque'a.";
    cout << "\n5. Usun element z tylu deque'a.";
    cout << "\n6. Usun wszystkie elementy z deque'a.";
    cout << "\n7. Pierwszy element deque'a.";
    cout << "\n8. Ostatni element deque'a";
    cout << "\n9. Wyjscie";

    while(zakoncz==false)
    {
        cout << "\nTwoj wybor: ";
        cin >> wybor;

        switch(wybor)
        {
        case 1:
            {
                d.wyswietl();
                cout << "\nRozmiar = " << d.rozmiar();
                break;
            }
        case 2:
            {
                cout << "\nCo chcesz dodac: ";
                cin >> znak;
                d.dodaj_przod(znak);
                break;
            }
        case 3:
            {
                cout << "\nCo chcesz dodac: ";
                cin >> znak;
                d.dodaj_tyl(znak);
                break;
            }
        case 4:
            {
                d.usun_przod();
                break;
            }
        case 5:
            {
                d.usun_tyl();
                break;
            }
        case 6:
            {
                d.usun_wszystkie();
                break;
            }
        case 7:
            {
                if(d.rozmiar()==0)
                {
                    cout << "\nnie ma nic";
                }
                else
                    cout << "\n" << d.pierwszy();
                break;
            }
        case 8:
            {
                 if(d.rozmiar()==0)
                {
                    cout << "\nnie ma nic";
                }
                else
                    cout << "\n" << d.ostatni();
                break;
            }
        case 9:
            {
                zakoncz = true;
                break;
            }
        }
    }

    return 0;
}
