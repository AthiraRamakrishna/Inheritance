#include <iostream>
#include <string>
class Base
{
    int m_val{};
    
    public:
    Base(int val=0):m_val{val}
    {
        std::cout<<"Base constructor"<<std::endl;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Base& b)
    {
        out<<"In Base\n";
        out<<b.m_val;
        return out;
    }
    ~Base(){}
    
    int getvalue() const {return m_val;}
    protected:
    void printvalue() const {std::cout<<m_val<<std::endl;}
};

class Derived : public Base
{
    public:
    Derived(int val=0):Base(val)
    {
        std::cout<<"Derived constructor"<<std::endl;
    }
    
    ~Derived(){}
    
    int getvalue() = delete;// mark this function as inaccessible
    friend std::ostream& operator<<(std::ostream& out, const Derived& d)
    {
        out<<"In Derived\n";
        out<< static_cast<const Base&>(d);
        return out;
    }
    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    using Base::printvalue;//not no paranthesis here
};

int main()
{
    Derived d{1};
    std::cout<<d<<std::endl;
    d.printvalue();
    //You can only change the access specifiers of base members the derived class would normally be able to access. 
    //Therefore, you can never change the access specifier of a base member from private to protected or public, 
    //because derived classes do not have access to private members of the base class.
    
    std::cout<<static_cast<const Base&>(d).getvalue()<<std::endl;// because getvalue() is deleted in the derived class
}
