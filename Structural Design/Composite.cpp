/*


                                <<interface>>
                                Component
                               # *parent: Component  
                                _____________               <----------------------
                                + setParent                                         |
                                + getParent
                                + virtual add
                                + virtual remove
                                + virtual isComposite
                                + virtual someOperation
                                    ^                                               |
                                    |                                               |
                                    |                                               |
                ______________________________________                              |
                |                                   |                               |
                |                                   |                               |
        ConcreteComponent                       Composite       <c>----------------
        .....                               # children: list<Component*>
        _________________                   __________________
        +someOperation                      + Add
                                            + remove
                                            + isComposite
                                            + someOperation
                

*/

// Composite.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

// class component
// class leaf
// class composite

class Component
{
public:
	Component(Component* comp) :_parent(comp) {}
	Component() {}
	~Component() {}
	// some operation 
	void setParent(Component* comp) { _parent = comp; }
	Component* getParent() { return _parent; }
	virtual void add(Component* comp) {}
	virtual void remove(Component* comp) {};
	virtual bool isComposite() { return false; }
	virtual std::string someOperation() const = 0;
protected:
	Component* _parent;

};

class Leaf : public Component
{
public:
	Leaf(){}
	~Leaf() {}
	
	std::string someOperation() const override
	{
		return "Leaf";
	}
};

class Composite : public Component
{
public:
	Composite(){} 
	~Composite(){}
	// some operation
	void add(Component* comp)
	{
		_list.push_back(comp);
		setParent(this);
	}

	void remove(Component* comp)
	{
		_list.remove(comp);
		setParent(nullptr);
	}

	bool isComposite() { return true; }
	std::string someOperation() const override
	{
		std::string result;
		for (const Component* comp : _list)
		{
			if (comp == _list.back())
				result += comp->someOperation();
			else
				result += comp->someOperation() + "+";
		}
		return "Branch(" + result + ")";
	}
	
private:
	std::list<Component*> _list;
};

void clientCode(Component* c)
{
	cout << c->someOperation();
}

void clientCode(Component* c1, Component* c2)
{
	if (c1->isComposite())
		c1->add(c2);

	cout << c1->someOperation();
}


int main()
{

	// simple application
	Component* simple = new Leaf();
	clientCode(simple);
	cout << endl;

	// complex application
	Component* tree = new Composite();
	Component* branch1 = new Composite();
	Component* branch2 = new Composite();

	Component* leaf1 = new Leaf();
	Component* leaf2 = new Leaf();
	Component* leaf3 = new Leaf();

	// Add leaf into branch
	branch1->add(leaf1);
	branch1->add(leaf2);
	clientCode(branch1);
	cout << endl;

	branch2->add(leaf3);
	tree->add(branch1);
	tree->add(branch2);
	clientCode(tree);
	cout << endl;

	cout << "No need to check" << endl;
	clientCode(tree, simple);

}