#include <iostream>
#include <string>
using namespace std;


class BreadImpl
{
public:
    virtual string shape() = 0;
};


class TriaBread : public BreadImpl
{
public:
    string shape()
    {
        return "triangle";
    }
};


class RectBread : public BreadImpl
{
public:
    string shape()
    {
        return "rectangle";
    }
};


class Bread
{
public:
    void setImpl(BreadImpl *impl)
    {
        this->_impl = impl;
    }

    virtual string look()
    {
        return _impl->shape();
    }

private:
    BreadImpl *_impl;
};


class WhiteBread : public Bread
{
public:
    string look()
    {
        return Bread::look() + " White";
    }
};


class BlackBread : public Bread
{
public:
    string look()
    {
        return Bread::look() + " Black";
    }
};


void BridgeTest()
{
    Bread *bread = new BlackBread;
    bread->setImpl(new RectBread);
    cout << bread->look() << endl;
}
