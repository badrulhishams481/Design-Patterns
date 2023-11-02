/*

                        <<Target>>
                    ...
                    ____________________
                    + SomeOperation
                            ^
                            |
                            |
                            |
                        Adapter                                 Adaptee
                    - *adapter:Adaptee                      .....
                    _____________________   ------------->  _______________
                    +Operation Adapter                      +WeirdOperation

*/

#include<iostream>
#include<algorithm>

using namespace std;

// target
// adapter
// adaptee

class Target
{
public:
    Target(){}
    ~Target(){}

    // some operations
    virtual std::string request() const
    {
        return "Target is the default behavior";
    }
};

class Adaptee
{
public:
    Adaptee(){}
    ~Adaptee(){}

    // some operations
    std::string weirdRequest() const
    {
        return "roivaheb tluafed eht si tegraT";
    }
};

class Adapter : public Target
{
public:
    Adapter(Adaptee* adaptee):adaptee(nullptr)
    {}
    ~Adapter(){}

    // some operations
    std::string request() const override
    {
        std::string toReverse = this->adaptee->weirdRequest();
        std::reverse(toReverse.begin(), toReverse.end());
        return "Adapter: (Translated) " + toReverse;
    }
private:
    Adaptee* adaptee;
};

void clientCode(Target& target)
{
   cout << target.request(); 
}

int main ()
{
    Target* target = new Target();
    clientCode(*target);
    cout <<" --------------------- " << endl;
    Adaptee* adaptee = new Adaptee();
    cout << adaptee->weirdRequest();
    cout << "--------------------- " << endl;
    Adapter* adapter = new Adapter(adaptee);
    clientCode(*adapter);

    return 0;
}