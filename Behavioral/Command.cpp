#include <iostream>
using namespace std;


class Receiver
{
public:
    void Action()
    {
        cout << "An action invoked!" << endl;
    }
};


class Command
{
public:
    virtual void Execute() = 0;

protected:
    Command()
    {

    }
};


class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Receiver *receiver) :
        _receiver(receiver)
    {

    }

    void Execute()
    {
        _receiver->Action();
    }

private:
    Receiver *_receiver;
};


class Invoker
{
public:
    void invoke(Command *command)
    {
        command->Execute();
    }
};


void CommandTest()
{
    Invoker *invoker = new Invoker();
    Command *command = new ConcreteCommand(new Receiver());
    invoker->invoke(command);
}
