#include <iostream>
#include <vector>
using namespace std;


class Observer
{
public:
    virtual void Update() = 0;
};


class Subject
{
public:
    void Add(Observer *o)
    {
        v.push_back(o);
    }

    void Notify()
    {
        for (size_t i = 0; i < v.size(); i++) {
            v.at(i)->Update();
        }
    }

private:
    vector<Observer *> v;
};


class ConcreteObserver : public Observer
{
public:
    void Update()
    {
        cout << "UPdated!" << endl;
    }
};


int main()
{
    Subject sub;
    ConcreteObserver co;
    sub.Add(&co);
    sub.Notify();
}
