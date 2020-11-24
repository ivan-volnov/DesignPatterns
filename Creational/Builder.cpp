#include <cstdio>


class Dish
{
public:
    int oil;
    int ingredient;
    int salt;

    void eat()
    {
        printf("a dish with %dg oil, %dg ingredient and %dg salt!", this->oil, this->ingredient, this->salt);
    }
};


class Pot
{
public:
    virtual void putOil(int n) = 0;
    virtual void putIngredient(int n) = 0;
    virtual void putSalt(int n) = 0;
    virtual Dish *getDish()
    {
        return nullptr;
    }
};


class Cook
{
public:
    virtual Dish *createDish(Pot *pot) = 0;
};


class WangCook : public Cook
{
public:
    Dish *createDish(Pot* pot)
    {
        pot->putOil(4);
        pot->putIngredient(200);
        pot->putSalt(2);
        return pot->getDish();
    }

};


class LiCook : public Cook
{
public:
    Dish *createDish(Pot *pot)
    {
        pot->putOil(8);
        pot->putIngredient(200);
        pot->putSalt(6);
        return pot->getDish();
    }
};


class Saucepan : public Pot
{
public:
    Saucepan()
    {
        dish = new Dish();
    }

    void putOil(int n)
    {
        dish->oil = n;
    }

    void putIngredient(int n)
    {
        dish->ingredient = n;
    }

    void putSalt(int n)
    {
        dish->salt = n;
    }

    Dish *getDish()
    {
        return dish;
    }

private:
    Dish *dish;
};


class PressurePot : public Pot
{
public:
    PressurePot()
    {
        dish = new Dish();
    }

    void putOil(int n)
    {
        dish->oil = n;
    }

    void putIngredient(int n)
    {
        dish->ingredient = n;
    }

    void putSalt(int n)
    {
        dish->salt = n + 1;
    }

    Dish *getDish()
    {
        return dish;
    }

private:
    Dish *dish;
};


class Eater
{
public:
    Eater()
    {
        Cook *cook = new WangCook();
        Dish *dish = cook->createDish(new Saucepan);
        dish->eat();
    }
};


void BuilderTest()
{
    Eater eater;
}
