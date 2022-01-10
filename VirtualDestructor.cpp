#include <iostream>
class Base
{
public:
    virtual ~Base() // note: virtual
    {
        std::cout << "Calling ~Base()\n";
    }
};

class Derived: public Base
{
private:
    int* m_array;

public:
    Derived(int length)
      : m_array{ new int[length] }
    {
    }

    virtual ~Derived() // note: virtual
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main()
{
    Derived *derived { new Derived(5) };
    Base *base { derived };

    delete base;
//Because base is a Base pointer, when base is deleted, 
//the program looks to see if the Base destructor is virtual. 
//It’s not, so it assumes it only needs to call the Base destructor.
//However, we really want the delete function to call Derived’s destructor (which will call Base’s destructor in turn), 
//otherwise m_array will not be deleted. We do this by making Base’s destructor virtual:
    return 0;
}
