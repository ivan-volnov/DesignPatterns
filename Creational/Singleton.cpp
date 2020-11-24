class Singleton
{
public:
    static Singleton *instance()
    {
        static Singleton _instance;
        return &_instance;
    }

private:
    Singleton() { }
};


void SingletonTest()
{
    Singleton *single = Singleton::instance();
}
