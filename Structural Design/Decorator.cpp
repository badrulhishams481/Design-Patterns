/*


                                <<interface>>
                                Component
                                ...
                                _____________               <----------------------
                                +SomeOperation                                      |
                                    |                                               |
                                    |                                               |
                                    |                                               |
                ______________________________________                              |
                |                                   |                               |
                |                                   |                               |
        ConcreteComponent                       Decorator       <c>----------------
        .....                               - wrapee: Component
        _________________                   __________________
        +someOperation                      +Decorator(s:Component)
                                            + someOperation
                                                    |
                                                    |
                                            __________________
                                            |               |
                                    ConcreteDecoratorA  ConcreteDecoratorB
                

*/

#include <iostream>

using namespace std;

// component
// concrete component
// decorator
// concrete1 decorator
// concrete2 decorator

class Component
{
public:
    Component(){}
    ~Component(){}
    // some operation
    virtual std::string someOperation() const = 0;
};

class ConcreteComponent : public Component
{
public:
    ConcreteComponent(){}
    ~ConcreteComponent(){}
    // some operation
    std::string someOperation() const  override
    {
        return " Concrete Component \n";
    }
};

class Decorator : public Component
{
public:
    Decorator(Component* comp):_comp(comp){}
    ~Decorator(){}
    // some operation
    std::string someOperation() const override
    {
        return " Decorator Base + " + this->_comp->someOperation();
    }

protected:
    Component* _comp;
};

class ConcreteDecorator1 : public Decorator
{
public:
    ConcreteDecorator1(Component* comp):Decorator(comp){}
    ~ConcreteDecorator1(){}
    // some operation
    std::string someOperation() const override
    {
        return " Concrete Decorator 1: " +  Decorator::someOperation();
    }
};

class ConcreteDecorator2 : public Decorator
{
public:
    ConcreteDecorator2(Component* comp):Decorator(comp){}
    ~ConcreteDecorator2(){}
    // some operation
    std::string someOperation() const override
    {
        return " Concrete Decorator 2: " +  Decorator::someOperation();
    }
};

void clientCode(Component* comp)
{
    cout << comp->someOperation();
}

int main()
{
    Component* comp = new ConcreteComponent();
    clientCode(comp);

    ConcreteDecorator1* concreteDec1 = new ConcreteDecorator1(comp);
    clientCode(concreteDec1);

    return 0;
}