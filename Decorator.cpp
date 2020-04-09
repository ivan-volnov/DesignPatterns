#include <iostream>
#include <string>
using namespace std;


class Paper
{
public:
    virtual string draw() = 0;
};


class BasicPaper : public Paper
{
public:
    string draw()
    {
        return "This is a basic paper";
    }
};


class Decorator : public Paper
{
public:
    Decorator(Paper *paper) :
        _paper(paper)
    {

    }

    string draw()
    {
        return _paper->draw();
    }

private:
    Paper *_paper;
};


class LineDecorator : public Decorator
{
public:
    LineDecorator(Paper *paper) :
        Decorator(paper)
    {

    }

    string draw()
    {
        return Decorator::draw() + ", with linedecorator";
    }
};


class BorderDecorator : public Decorator
{
public:
    BorderDecorator(Paper *paper) :
        Decorator(paper)
    {

    }

    string draw()
    {
        return Decorator::draw() + ", with borderdecorator";
    }
};


int main()
{
    Paper *paper = new LineDecorator(new BorderDecorator(new BasicPaper));
    cout << paper->draw() << endl;
}
