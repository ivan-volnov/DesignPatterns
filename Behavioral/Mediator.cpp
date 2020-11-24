#include <iostream>
using namespace std;


class Client
{
public:
    virtual void actionPerformed() = 0;
    virtual void dosomething() = 0;
};


class Mediator
{
public:
    void setClient1(Client *client)
    {
        this->_client1 = client;
    }

    void setClient2(Client *client)
    {
        this->_client2 = client;
    }

    void client1Call()
    {
        _client2->dosomething();
    }

    void client2Call()
    {
        _client1->dosomething();
    }

private:
    Client *_client1;
    Client *_client2;
};


class Client1 : public Client
{
public:
    Client1(Mediator *mediator) :
        _mediator(mediator)
    {

    }

    void actionPerformed()
    {
        _mediator->client1Call();
    }

    void dosomething()
    {
        cout << "client1 text set!" << endl;
    }

private:
    Mediator *_mediator;
};


class Client2 : public Client
{
public:
    Client2(Mediator *mediator) :
        _mediator(mediator)
    {

    }

    void actionPerformed()
    {
        _mediator->client2Call();
    }

    void dosomething()
    {
        cout << "client2 data set!" << endl;
    }

private:
    Mediator *_mediator;
};


void MediatorTest()
{
    Mediator *mediator = new Mediator();
    Client *client1 = new Client1(mediator);
    Client *client2 = new Client2(mediator);
    mediator->setClient1(client1);
    mediator->setClient2(client2);
    client1->actionPerformed();
}
