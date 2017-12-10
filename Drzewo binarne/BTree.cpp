/*
    AUTOR: RAFAL ROZYCKI 226367
    SRODA 12:00

    Program jest implementacja drzewa binarnego

    Program posiada menu w ktorym mozna przetestowac kilka funkcji drzewa binarnego
    1. Wyswietlanie
    2. Dodawanie elementu
    3. Usuwanie elementu
    4. Wyswietlanie minimalnego i maksymalnego elementu.

    Dodawanie kluczu do drzewa odbywa sie na zasadzie - wieksze lub rowne od korzenia na prawo,
    a mniejsze na lewo.

    Usuwanie kluczu z drzewa odbywa sie poprzez usuwanie przez zlaczanie.

*/

#include <iostream>

using namespace std;

/*--------------------------------*/

template<typename T>
class Node
{
public:
    Node<T> *left;
    Node<T> *right;
    T data;
    Node();
};

template<typename T>
Node<T>::Node()
{
    left=nullptr;
    right=nullptr;
}



/*--------------------------------*/

/*
    Drzewa posiada korzen wskazujacy na pierwszy element oraz
    metody prywatne i publiczne o prawie takich samych nazwach, ale
    te prywatne przyjmuja wskaznik na wezel, bo bez niego niemozliwe jest przeszukanie drzewa binarnego.
*/
template<typename T>
class BTree
{
    Node<T>     *root;

    Node<T>*    _Min(Node<T> *ptr);
    T           _Max(Node<T> *ptr);
    Node<T>*    _DeleteNode(T value, Node<T> *ptr);
    void        _Insert(T value, Node<T> *ptr);
    void        _print(Node<T> *ptr);
    Node<T>*    Create(T value);
    void        DeleteNode(Node<T>*& node);
public:

    T       Min();
    T       Max();
    void    Insert(T value);
    void    print();
    void    DeleteElement(T& el);

    BTree();
};

// Konstruktor drzewa binarnego
template<typename T>
BTree<T>::BTree()
{
    root = nullptr;
}

// Metoda _Min przyjmuje korzen oraz
// zwraca wskaünik na wezel z najmniejszym kluczem
template<typename T>
Node<T>* BTree<T>::_Min(Node<T> *ptr)
{
    if(root==nullptr)
    {
        string e = "Puste drzewo.";
        throw e;
    }
    else{
        while(ptr->left != nullptr)
        {
            ptr = ptr->left;
        }
        return ptr;
    }
}

// Metoda zwraca minimalny klucz przeszukujac drzewo od korzenia
template<typename T>
T BTree<T>::Min()
{
    return _Min(root)->data;
}

// Metoda _Min przyjmuje korzen oraz
// zwraca wskaünik na wezel z najwiekszym kluczem
template<typename T>
T BTree<T>::_Max(Node<T> *ptr)
{
    if(root==nullptr)
    {
        string e = "Puste drzewo.";
        throw e;
    }
    else{
        while(ptr->right != nullptr)
        {
            ptr = ptr->right;
        }
        return ptr->data;
    }
}

// Metoda zwraca maksymalny klucz przeszukujac drzewo od korzenia
template<typename T>
T BTree<T>::Max()
{
    return _Max(root);
}


// Metoda Create tworzy nowy element
template<typename T>
Node<T>* BTree<T>::Create(T value)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = value;
    newNode->left = newNode->right = nullptr;

    return newNode;
}

// Metoda Insert wstawia klucz o zadanej wartosci do drzewa
// W tej metodzie jest wywolywana prywatna metoda _Insert,
// po to aby miec dostep do korzenia
template<typename T>
void BTree<T>::Insert(T value)
{
    _Insert(value,root);
}

// Metoda _Insert wstawia klucz do drzewa szukajac miejsca
// poczynajac od korzenia
template<typename T>
void BTree<T>::_Insert(T value, Node<T> *ptr)
{
    // Jesli korzen jest pusty to tworzymy nowy wezel
    if(root == nullptr)
    {
        root = Create(value);
    }
    else if(value < ptr->data)
    {
        if(ptr->left != nullptr)
        {
            _Insert(value, ptr->left);
        }
        else
            ptr->left = Create(value);
    }
    else if(value >= ptr->data)
    {
        if(ptr->right != nullptr)
        {
            _Insert(value, ptr->right);
        }
        else
        {
            ptr->right = Create(value);
        }
    }
}

// Metoda _print przyjmuje wskaznik na wezel i
// wyswietla drzewo binarne od korzenia
template<typename T>
void BTree<T>::_print(Node<T> *ptr)
{
    if(root == nullptr)
    {
        cout << "\nDrzewo binarne jest puste.";
    }
    else
    {
        if(ptr->left != nullptr)
        {
            _print(ptr->left);
        }
        cout << ptr->data << " ";
        if(ptr->right != nullptr)
        {
            _print(ptr->right);
        }
    }
}

// Metoda print wyswietla drzewo binarne
template<typename T>
void BTree<T>::print()
{
    _print(root);
}


/*
    Funkcja DeleteNode to prywatna metoda do usuwania elementu z drzewa binarnego.
    Metoda znajduje nastepnika na miejsce usuwanego wezla
*/
template<typename T>
void BTree<T>::DeleteNode(Node<T>*& node)
{
    Node<T> *temp = node; // Tworzymy wezel pomocniczy ktory bedzie wskazywal na node
    // Dopoki wezel nie jest pusty
    if(node != nullptr)
    {
        // jesli wezel nie ma prawego dziecka to idziemy w lewo
        if(node->right == nullptr)
        {
            node = node->left;
        }
        // jesli wezel nie ma lewego dziecka to idziemy w prawo
        else if(node->left == nullptr)
        {
            node = node->right;
        }
        else
        {
            // Temp wskazuje na lewe dziecko node'a
            temp = node->left;
            // Dopoki temp nie bedzie mial prawych dzieci idziemy w prawo
            while(temp->right != nullptr)
                temp = temp->right;
            // Prawe dziecko temp to prawe dziecko node'a
            temp->right = node->right;

            // temp wskazuje na node
            temp = node;
            // node wskazuje na swoje lewe dziecko
            node = node->left;
        }
        // usuwamy wezel
        delete temp;
    }
}

/*
    Metoda DeleteElement to publiczna metoda usuwania wskazanego przez uzytkownika klucza
*/
template<typename T>
void BTree<T>::DeleteElement(T& el)
{
    Node<T> *node = root;
    Node<T> *prev = nullptr;

    while(node != nullptr)
    {
        if(node->data == el) // Jesli w wezle jest zadana wartosc to przerywamy
            break;
        prev = node;
        if(node->data < el)     // jesli wartosc zadana jest wieksza od tej w wezle
            node = node->right; // idziemy w prawo
        else
            node = node->left;  // jesli nie to w lewo
    }
    if(node != nullptr && node->data == el) // jesli wezel nie jest pusty i jego wartosc jest rowna z zadana
    {
        // Jesli wezel jest jest korzeniem to usuwamy korzen
        if(node == root)
        {
            DeleteNode(root);
        }
        // Jesli lewe dziecko jest zadanym wezlem to je usuwamy
        // jesli prawe to wlasnie je usuwamy
        else if(prev->left == node)
        {
            DeleteNode(prev->left);
        }
        else DeleteNode(prev->right);
    }
    else if(root != nullptr)
        cout << "Elementu " << el << " nie ma w drzewie";
    else
    {
        cout << "\nDrzewo puste.";
    }

}

/*--------------------------------*/


int main()
{
    BTree<int> T;
    bool zakoncz=false;
    int wybor=0;
    int el;

    cout << "\n1. Wyswietl drzewo binarne.";
    cout << "\n2. Dodaj element.";
    cout << "\n3. Usun element.";
    cout << "\n4. Maksmymalny element w drzewie.";
    cout << "\n5. Minimalny element w drzewie.";
    cout << "\n6. Wyjscie";


    while(!zakoncz)
    {
        cout << "\nTwoj wybor: ";
        cin >> wybor;

        switch(wybor)
        {
        case 1:
            {
                T.print();
                break;
            }
        case 2:
            {
                cout << "\nCo: ";
                cin >> el;
                T.Insert(el);
                break;
            }
        case 3:
            {

                cout << "\nCo: ";
                cin >> el;
                T.DeleteElement(el);
                break;

            }
        case 4:
            {
                try{
                cout << "\nMaksymalny element: " << T.Max();
                } catch(string e) { cout << "\n" << e;}
                break;
            }
        case 5:
        {
            try{
            cout << "\nMinimalny element: " << T.Min();
            } catch(string e) {cout << "\n" << e;}
            break;
        }
        case 6:
            {
                zakoncz=true;
                break;

            }

        }
    }


    return 0;
}
