
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
