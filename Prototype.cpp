#include <iostream>
using namespace std;


class File
{
public:
    virtual int getWidth() = 0;
    virtual File* clone() = 0;
};


class A5File : public File
{
public:
    A5File(int n) :
        width(n)
    {

    }

    int getWidth()
    {
        return width;
    }

    File *clone()
    {
        return new A5File(this->width);
    }

private:
    int width;
};


class A4File : public File
{
public:
    A4File(int n) :
        width(n)
    {

    }

    int getWidth()
    {
        return width;
    }

    File *clone()
    {
        return new A5File(this->width);
    }

private:
    int width;
};


class Tools
{
public:
    virtual void go() = 0;
};


class Stapler : public Tools
{
public:
    Stapler(File *file)
    {
        this->file = file->clone();
    }

    void go()
    {
        cout << "This is the stapler, this is " << this->file->getWidth() << " width!" << endl;
    }

private:
    File *file;
};


class Cutter : public Tools
{
public:
    Cutter(File *file)
    {
        this->file = file->clone();
    }

    void go()
    {
        cout << "This is the cutter, this is " << this->file->getWidth() << "width" << endl;
    }

private:
    File *file;
};


int main()
{
    Tools *tool = new Stapler(new A5File(123));
    tool->go();
}
