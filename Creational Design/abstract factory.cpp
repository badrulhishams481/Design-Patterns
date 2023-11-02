/*


                            [Creator]
                    ...
                    ____________________________                                 <<interface>>    <-----Client----->  <<interfacee>>
                    + createProductA(): ProductA                                   ProductA                                productB
                    + createProductB(): ProductB
                                ^                                            ______________________                     ______________________                     
                                |                                                + doStuff()                            + doStuff()
                                |                                                        ^
                    ____________|_______________                                         | 
                    |                          |        ---------------->        --------|------------
                    |                          |                                 |                   |
                    |                          |                                 |                   |
            ConcreteCeator1               ConcreteCreator2              ConcreteProduct1         ConcreteProduct2
            ...                             ... 
            ________________                ________________
            +createProductA1():ProductA1    + createProductA2():ProductA2
            +createProductB1():ProductB1    + createProductB2():ProductB2


*/

#include<iostream>

using namespace std;

// productA interface
// productA , product 1
// productA, product 2

// productB interface
// productB, product 1
// productB, product 2

// abstract factory
// factory1
// factory2

// client

class IProductA
{
public:
    IProductA(){}
    virtual ~IProductA(){}

    // some operation
    virtual std::string someOperation() const = 0;
};

class ProductA1 : public IProductA
{
public:
    ProductA1(){}
    ~ProductA1(){}

    // some operation 
    std::string someOperation() const override
    {
        return "This is ProductA1";
    }
};

class ProductA2 : public IProductA
{
public:
    ProductA2(){}
    ~ProductA2(){}

    // some operation 
    std::string someOperation() const override
    {
        return "This is ProductA2";
    }
};

class IProductB
{
public:
    IProductB(){}
    virtual ~IProductB(){}

    // some operation
    virtual std::string someOperation() const = 0;
    virtual std::string collaboration(const IProductA& product) const = 0;
};

class ProductB1 : public IProductB
{
public:
    ProductB1(){}
    ~ProductB1(){}

    // some operation 
    std::string someOperation() const override
    {
        return "This is ProductB1";
    }
    std::string collaboration(const IProductA& product) const override
    {
        return "The result of B1 collaborate with" + product.someOperation();
    }
};

class ProductB2 : public IProductB
{
public:
    ProductB2(){}
    ~ProductB2(){}

    // some operation 
    std::string someOperation() const override
    {
        return "This is ProductB2";
    }
    std::string collaboration(const IProductA& product) const override
    {
        return "The result of B1 collaborate with" + product.someOperation();
    }
};

class AbstractFactory
{
public:
    AbstractFactory(){}
    ~AbstractFactory(){}

    virtual IProductA* createProductA() const = 0;
    virtual IProductB* createProductB() const = 0;
};

class Factory1 : public AbstractFactory
{
public:
    Factory1(){}
    ~Factory1(){}

    IProductA* createProductA() const override
    {
        return new ProductA1;
    }
    IProductB* createProductB() const override
    {
        return new ProductB1;
    }
};

class Factory2 : public AbstractFactory
{
public:
    Factory2(){}
    ~Factory2(){}

    IProductA* createProductA() const override
    {
        return new ProductA2;
    }
    IProductB* createProductB() const override
    {
        return new ProductB2;
    }
};
// client 
void clientCode(const AbstractFactory& af)
{
    const IProductA* pA = af.createProductA();
    const IProductB* pB = af.createProductB();
    cout<< pB->someOperation() << "\n";
    cout<< pB->collaboration(*pA) << "\n";
    delete pA;
    delete pB;
}

int main()
{
   Factory1* f1 = new Factory1(); 
   clientCode(*f1);
   Factory2* f2 = new Factory2(); 
   clientCode(*f2);
   delete f1;
   delete f2;

    return 0;
}
