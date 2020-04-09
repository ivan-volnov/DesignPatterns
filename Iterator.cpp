#include <iostream>
using namespace std;


class List;


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
class ListIterator : public Iterator<T>
{
public:
    ListIterator<T>(List *list) : _list(list), count(0) { }
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


class List
{
public:
    friend class ListIterator<int>;
    List()
    {
        for (int i = 0; i < 10; i++) {
            _a[i] = i;
        }
    }

    Iterator<int> *CreateIterator()
    {
        return new ListIterator<int>(this);
    }

private:
    int _a[10];
};


int main()
{
    List list;
    Iterator<int> *itr = list.CreateIterator();
    cout << itr->CurrentItem() << endl;
    itr->Next();
    cout << itr->CurrentItem() << endl;
}

