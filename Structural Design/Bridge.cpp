/*


                        <<Abstraction>>       <>--------------->              <<interface>>
                    - i : implementation                                    Implementation 
                    _________________                                       _______________
                    +feature1()                                             + method1()
                    +feature2()                                             + method2()
                            ^                                                       ^
                            |                                                       |
                            |                                                       |
                ________________________                                   _____________________
                |                       |                                   |                   |
            Circle                  Square                              Red                 Blue                      
*/

#include<iostream>

using namespace std;

//  implementation 
// concreteImpl1
//  concreteImpl2

// abstract
// concrete1Abs

class Implementation
{
public:
    Implementation(){}
    ~Implementation(){}
    // some operation
    virtual std::string someOperation() const = 0;
};

class ConcreteImpl1 : public Implementation
{
public:
    ConcreteImpl1(){}
    ~ConcreteImpl1(){}
    //some operation
    std::string someOperation() const  override
    {
        return "Concrete Implementation 1 :";
    }
};

class ConcreteImpl2 : public Implementation
{
public:
    ConcreteImpl2(){}
    ~ConcreteImpl2(){}
    //some operation
    std::string someOperation() const  override
    {
        return "Concrete Implementation 2 :";
    }
};

class Abstract
{
public:
    Abstract(Implementation* imp):_impl(imp){}
    ~Abstract(){}
    // some operation
    virtual std::string someOperation() const 
    {
        return "Asbraction: Base Operation " + this->_impl->someOperation();
    }

protected:
    Implementation* _impl;
};

class ConcreteAbstract : public Abstract
{
public: 
    ConcreteAbstract(Implementation* imp): Abstract(imp){}
    ~ConcreteAbstract(){}
    //some operation
    std::string someOperation() const override
    {
        return "Concrete Abstraction: Concrete Operation " + this->_impl->someOperation(); 
    }
};

void clientCode(const Abstract& abs)
{
    std::cout << abs.someOperation();
}

int main()
{
    Implementation* impl = new ConcreteImpl1();
    Abstract* abs = new Abstract(impl);
    clientCode(*abs);
    cout << endl;
    delete impl;
    delete abs;

    // create implementation for B and using concrete abstracrt
    impl = new ConcreteImpl2();
    abs = new ConcreteAbstract(impl);
    clientCode(*abs);
    cout<< endl;
    delete impl;
    delete abs;

    return 0;
}