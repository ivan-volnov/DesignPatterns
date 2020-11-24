#include <iostream>
#include <string>
#include <cctype>
using namespace std;


class Context
{
public:
    Context(string s) :
        _message(s)
    {

    }

    string &getMsg()
    {
        return _message;
    }

private:
    string _message;
};


class AbstractExpression
{
public:
    virtual void interpret(Context &) = 0;
};


class UpExpression : public AbstractExpression
{
public:
    void interpret(Context &context)
    {
        string *s = &context.getMsg();
        for (size_t i = 0; i < s->size(); i++) {
            s->at(i) = toupper(s->at(i));
        }
    }
};


class AddExpression : public AbstractExpression
{
public:
    void interpret(Context &context)
    {
        string *s = &context.getMsg();
        s->insert(0, "{");
        s->append("}");
    }
};


void InterpreterTest()
{
    Context context("abcDeFGhi");
    (new UpExpression())->interpret(context);
    (new AddExpression())->interpret(context);
    cout << context.getMsg() << endl;
}
