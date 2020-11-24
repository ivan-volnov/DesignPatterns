#include <iostream>
using namespace std;


typedef enum {READ, WRITE, EXECUTE, UNKNOWN} Type;


class IHandler
{
public:
    virtual void handle(Type arg)
    {

    }

protected:
    IHandler *_handler;
    IHandler(IHandler *handler) :
        _handler(handler)
    {

    }
};


class IReadHander : public IHandler
{
public:
    IReadHander(IHandler *handler) :
        IHandler(handler)
    {

    }

    void handle(Type arg)
    {
        if (arg == READ) {
            cout << "This Request is handled by IReadHander" << endl;
        } else if (IHandler::_handler != 0) {
            IHandler::_handler->handle(arg);
        }
    }
};


class IWriteHander : public IHandler
{
public:
    IWriteHander(IHandler *handler) :
        IHandler(handler)
    {

    }

    void handle(Type arg)
    {
        if (arg == WRITE) {
            cout << "This Request is handled by IWriteHander" << endl;
        } else if (IHandler::_handler != 0) {
            IHandler::_handler->handle(arg);
        }
    }
};


class IExecHander : public IHandler
{
public:
    IExecHander(IHandler *handler) :
        IHandler(handler)
    {

    }

    void handle(Type arg)
    {
        if (arg == EXECUTE) {
            cout << "This Request is handled by IExecHander" << endl;
        } else if (IHandler::_handler != 0) {
            IHandler::_handler->handle(arg);
        }
    }
};


void ChainOfResponsibilityTest()
{
    IHandler *readHandler = new IReadHander(0);
    IHandler *writeHandler = new IWriteHander(readHandler);
    IHandler *execHandler = new IExecHander(writeHandler);
    execHandler->handle(UNKNOWN);
}
