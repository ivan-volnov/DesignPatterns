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


int main()
{
    Singleton *single = Singleton::instance();
}
