#include <iostream>
using namespace std;


class subSystemOne
{
public:
    void MethodOne()
    {
        cout << "SubsystemMethodOne" << endl;
    }
};


class subSystemTwo
{
public:
    void MethodTwo()
    {
        cout << "SubsystemMethodTwo" << endl;
    }
};


class subSystemThree
{
public:
    void MethodThree()
    {
        cout << "SubsystemMethodThree" << endl;
    }
};


class subSystemFour
{
public:
    void MethodFour()
    {
        cout << "SubsystemMethodFour" << endl;
    }
};


class Facade
{
public:
    Facade()
    {
        one   = new subSystemOne();
        two   = new subSystemTwo();
        three = new subSystemThree();
        four  = new subSystemFour();
    }

    void MethodA()
    {
        cout << endl << "Method group A() ----" << endl;
        one->MethodOne();
        two->MethodTwo();
        four->MethodFour();
    }

    void MethodB()
    {
        cout << endl << "Method group B() ----" << endl;
        two->MethodTwo();
        three->MethodThree();
    }

    ~Facade()
    {
        delete one;
        delete two;
        delete three;
        delete four;
    }

private:
    subSystemOne *one;
    subSystemTwo *two;
    subSystemThree *three;
    subSystemFour *four;
};

void FacadeTest()
{
    Facade *facade = new Facade();

    facade->MethodA();
    facade->MethodB();

    delete facade;
}
