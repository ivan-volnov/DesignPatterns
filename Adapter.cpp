#include <iostream>
using namespace std;


class Car
{
public:
    virtual void start()
    {
        cout << "Engine start!" << endl;
    }
};


class Bike
{
public:
    virtual void ride()
    {
        cout << "Ride a bike!" << endl;
    }
};


class Adapter : public Bike, private Car
{
public:
    void ride()
    {
        Car::start();
    }
};


class Adapter2 : public Bike
{
public:
    Adapter2(Car *car) :
        _car(car)
    {

    }

    void ride()
    {
        _car->start();
    }

private:
    Car *_car;
};


class DualAdapter : public Bike, public Car
{
public:
    void ride()
    {
        Car::start();
    }

    void start()
    {
        Bike::ride();
    }
};


class DualAdapter2 : public Bike
{
public:
    DualAdapter2(Car *car, Bike *bike) :
        _car(car), _bike(bike)
    {

    }

    void ride()
    {
        _car->start();
    }

    void start()
    {
        _bike->ride();
    }

private:
    Car *_car;
    Bike *_bike;
};


int main()
{
    Bike *bike = new DualAdapter2(new Car, new Bike);
    bike->ride();
}
