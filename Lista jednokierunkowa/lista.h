using namespace std;

template<typename T>
class Lista
{
    Element<T> *glowa;
public:
    T zmienna;



    Lista();

    void dodaj_tyl(T el); //x
    void dodaj_przod(T el);
    void usun_przod();
    void usun_tyl();
    void usun_wszystkie();
    void wyswietl();
};

// Dodawanie z przodu
template<typename T>
void Lista<T>::dodaj_przod(T el)
{
    // Tworzymy nowy element
    Element<T> *nowy = new Element<T>;

    // Przypisujemy nowemu elementowi wprowadzone dane
    nowy->dane = el;
    // Glowa wskazuje na nastepny element od nowego
    nowy->nastepny = glowa;
    // Glowa wskazuje teraz na nowy
    glowa=nowy;
}

//Dodawanie z przodu listy
template<typename T>
void Lista<T>::dodaj_tyl(T el)
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
        nowy->nastepny = nullptr; // najnowszy ostatni wskazuje na 0

    }
}

// Usuwanie z przodu listy
template<typename T>
void Lista<T>::usun_przod()
{
    // Zmienna pomocniczna
    Element<T> *stary = glowa;

    if(glowa==nullptr) // Jesli lista jest pusta
    {
        cout << "\nLista jest pusta.";
    }
    else
    {
        // Glowa wskazuje na nastepny element  liczac od poczatku
        // a nastepnie usuwamy stary
        glowa = stary->nastepny;
        delete stary;
    }
}

// Wyswietlanie listy
template<typename T>
void Lista<T>::wyswietl()
{
    // wskaznik na pierwszy element
    Element<T> *temp = glowa;

    // Komunikat jesli lista jest pusta
    if(temp==nullptr)
    {
        cout << "\nLista jest pusta.";
    }
    else
    {
        // Wyswietlamy dane
        while(temp)
        {
            cout << "\n" << temp->dane ;
            temp = temp->nastepny;
        }
    }
}

// Usuwanie z tylu
template<typename T>
void Lista<T>::usun_tyl()
{
    // Zmienna pomocnicza
    Element<T> *temp = glowa;

    if(glowa==nullptr) // Jesli lista jest pusta
    {
        cout << "\nLista jest pusta.";
    }
    else
    {
        // Jesli nastepny element od temp, ktory wskazuje na glowe to 0 to
        // usuwamy temp i glowa wskazuje na 0
        if(temp->nastepny==nullptr)
        {
            delete(temp);
            glowa=nullptr;
        }
        else
        {
            // Idziemy na koniec listy
            while(temp->nastepny)
            {

                // Szuakmy przedostatniego elementu
                if(temp->nastepny->nastepny==nullptr)
                {
                    // Usuwamy nastepny od temp
                    delete(temp->nastepny);
                    // Nastepny od temp wskazuje na 0
                    temp->nastepny=nullptr;
                    break;
                }
                else // Jesli jeszcze nie znaleziony przedostatni to idzemy dalej
                {
                    temp = temp->nastepny;
                }
            }
        }
    }
}

// Usuwanie wszystkich elementow listy
template<typename T>
void Lista<T>::usun_wszystkie()
{

    // Poki glowa nie wskazuje na 0 to
    // tworzymy wskazniki pomocnicze wskazujace na glowe, a glowa bedzie wskazywac na nastepne elementy
    // Na koniec usuwamy temp
    while(glowa!=nullptr)
    {
        Element<T> *temp = glowa;
        glowa = temp->nastepny;
        delete(temp);
    }
}




//Konstruktor listy
template<typename T>
Lista<T>::Lista()
{
    glowa = nullptr;
}
