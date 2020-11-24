#include <iostream>
using namespace std;



template<typename T>
class Iterator
{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual T CurrentItem() = 0;
};



template<typename T>
class ListIterator;



class List
{
    friend class ListIterator<int>;

public:
    List()
    {
        for (int i = 0; i < 10; i++) {
            _a[i] = i;
        }
    }

    Iterator<int> *CreateIterator();

private:
    int _a[10];
};



template<typename T>
class ListIterator : public Iterator<T>
{
public:
    ListIterator<T>(List *list) : count(0), _list(list)
    {

    }

    void First()
    {
        count = 0;
    }

    void Next()
    {
        count++;
    }

    bool IsDone()
    {
        return count >= 10;
    }

    T CurrentItem()
    {
        return _list->_a[count];
    }

private:
    int count;
    List *_list;
};



Iterator<int> *List::CreateIterator()
{
    return new ListIterator<int>(this);
}



void IteratorTest()
{
    List list;
    Iterator<int> *itr = list.CreateIterator();
    cout << itr->CurrentItem() << endl;
    itr->Next();
    cout << itr->CurrentItem() << endl;
}
