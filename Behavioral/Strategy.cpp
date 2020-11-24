#include <iostream>
using namespace std;


class Strategy
{
public:
    virtual void DoAlgorithm() = 0;
};


class Context
{
public:
    Context(Strategy *strategy)
    {
        _strategy = strategy;
    }

    void DoSomething()
    {
        _strategy->DoAlgorithm();
    }

private:
    Strategy *_strategy;
};


class ConcreteStrategyA : public Strategy
{
public:
    void DoAlgorithm()
    {
        cout << "This is strategy A" << endl;
    }
};


class ConcreteStrategyB : public Strategy
{
public:
    void DoAlgorithm()
    {
        cout << "This is strategy B" << endl;
    }
};


void StrategyTest()
{
    Context contexta(new ConcreteStrategyA);
    contexta.DoSomething();
    Context contextb(new ConcreteStrategyB);
    contextb.DoSomething();
}
