#include <iostream>
using namespace std;


class IObject
{
public:
    virtual void operation() = 0;
};


class IObjectImpl : public IObject
{
public:
    void operation()
    {
        cout << "operation by iobjectimpl" << endl;
    }
};


class IObjectProxy : public IObject
{
public:
    IObjectProxy()
    {
        object = new IObjectImpl;
    }

    void operation()
    {
        cout << "before operation" << endl;
        object->operation();
        cout << "after operation" << endl;
    }

private:
    IObject *object;
};


int main()
{
    IObject *object = new IObjectProxy;
    object->operation();
}
