#include <iostream>

class Base
{
    protected:
        int m_val{};
        
    public:
    Base(int val=0):m_val(val)
    {
        std::cout<<"Base"<<std::endl;
    }
    ~Base()
    {
        std::cout<<"~Base"<<std::endl;
    }
    
    virtual std::string getName() const {return "Base";}
    int getValue() const{return m_val;}
};


class Derived : public Base
{
    public:
    Derived(int val=0):Base(val)
    {
        std::cout<<"Derived"<<std::endl;
    }
    
    ~Derived()
    {
        std::cout<<"~Derived"<<std::endl;
    }
    
    virtual std::string getName() const {return "Derived";}
    int getValueDoubled() const{return m_val*2;}
};


int main()
{
    Derived d{2};
    std::cout<<"derived is a "<<d.getName()<<" has a value "<<d.getValue()<<std::endl;
    
    //setting Derived pointers and references to Derived objects:
    Derived& rd{d};
    std::cout<<"derived is a "<<rd.getName()<<" has a value "<<rd.getValue()<<std::endl;
    
    Derived* pd{&d};
    std::cout<<"derived is a "<<pd->getName()<<" has a value "<<pd->getValue()<<std::endl;
    
    //setting the base pointer and base reference to the derived object
    
    //It turns out that because brd and bpd are a Base reference and pointer, 
    //they can only see members of Base (or any classes that Base inherited). 
    //So even though Derived::getName() shadows (hides) Base::getName() for Derived objects, 
    //the Base pointer/reference can not see Derived::getName(). 
    //Consequently, they call Base::getName(), which is why rBase and pBase report that they are a Base rather than a Derived.
    
    Base& brd{d};
    std::cout<<"derived is a "<<brd.getName()<<" has a value "<<brd.getValue()<<std::endl;
    
    Base* bpd{&d};
    std::cout<<"derived is a "<<bpd->getName()<<" has a value "<<bpd->getValue()<<std::endl;
    
    //if the getName() is virtual it calls the derived->getName() function 
    
    //Best practice

    //Never call virtual functions from constructors or destructors.
}
