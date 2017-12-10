#include "element.h"

using namespace std;

template<typename T>
class Kolejka
{
    Element<T> *glowa;
public:
    T zmienna;

    Kolejka();

    void dodaj(T el);
    void usun();
    void wyswietl();
    void usun_wszystkie();
};

template<typename T>
Kolejka<T>::Kolejka()
{
    glowa=nullptr;
}

template<typename T>
void Kolejka<T>::dodaj(T el)
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
        nowy->nastepny = nullptr; // nastepny od nowego wskazuje na 0

    }
}

template<typename T>
void Kolejka<T>::usun()
{
    Element<T> *stary = glowa;

    if(glowa==nullptr)
    {
        cout << "\nKolejka jest pusta.";
    }
    else
    {
        glowa = stary->nastepny;
        delete stary;
    }
}

template<typename T>
void Kolejka<T>::usun_wszystkie()
{
    while(glowa!=nullptr)
    {
        Element<T> *temp = glowa;
        glowa = temp->nastepny;
        delete(temp);
    }
}

template<typename T>
void Kolejka<T>::wyswietl()
{
    Element<T> *temp = glowa;

    if(temp==nullptr)
    {
        cout << "\nKolejka jest pusta.";
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
