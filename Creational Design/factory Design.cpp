/*

                            [Creator]
                    ...
                    ____________________________        ---------------->       <<interface>>
                    + createProduct(): Product                                      Product
                                ^                                            ______________________
                                |                                                + doStuff()
                                |
                    ____________|_______________                                        ^
                    |                                                           --------|----------
                    |                                                           |                   |
                    |                                                           |                   |
            ConcreteCeatorA               ConcreteCreatorB              ConcreteProductA         ConcreteProductB
            ...                             ... 
            ________________                ________________
            +createProduct():Product        + createProduct():Product


*/

#include<iostream>


using namespace std;


// interface product
class Product
{
public:
   Product(){}
   virtual ~Product(){} 

   // some operation
   virtual std::string operation() const = 0;
};

// product A
class ProductA : public Product
{
public:
    ProductA(){}
    ~ProductA(){}

    // some operation
    std::string operation() const override
    {
        return "{ConcreteProduct A}";
    }
};
// product B
class ProductB : public Product
{
public:
    ProductB(){}
    ~ProductB(){}

    // some operation
    std::string operation() const override
    {
        return "{ConcreteProduct B}";
    }
};

// creator
// declares factory method that will return an object of a product class.
class Creator
{
public:
    Creator(): _product(nullptr)
    {}
    virtual ~Creator(){}

    // factory methods 
    virtual Product* factoryMethod() const = 0;

    // contains some core logic that relies on product objects.
    std::string someOperation() const
    {
        Product* product =  this->factoryMethod();
        std::string result = " - Creator class is called with" + product->operation();
        delete product;
        return result;
    }
private:
    Product* _product; // demo only
};

// creator A
class CreatorA : public Creator
{
public:
    CreatorA()
    {
        cout<<"The app started with CreatorA \n "; 
    }
    ~CreatorA(){}

    Product* factoryMethod() const override
    {
        return new ProductA();
    }
};

// creator B

class CreatorB : public Creator
{
public:
    CreatorB()
    {
        cout<<"The app started with CreatorB \n "; 
    }
    ~CreatorB(){}

    Product* factoryMethod() const override
    {
        return new ProductB();
    }
};

// client
void clientCode(const Creator& creator)
{
    std::cout   << " - Client: I'm not aware of the creator class \n"
                << creator.someOperation() << std::endl;
}


int main()
{
    Creator* creator = new CreatorA();
    clientCode(*creator);

    Creator* creator2 = new CreatorB();
    clientCode(*creator2);

    delete creator;
    delete creator2;

    return 0;
}