#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Player
{
public:
    Player() {} // Default constructor

    // Constructor
    Player(string _name, unsigned _health, unsigned _exp) : name(_name), health(_health), exp(_exp) {}
    string getname() { return name; }
    unsigned gethealth() { return health; }
    unsigned getexp() { return exp; }

    // attributes
    string name;
    unsigned health{};
    unsigned exp{};

    // methods
    void text(string text)
    {
        cout << text << endl;
    }
    bool is_dead()
    {
        if (health == 0)
        {
            cout << "You are dead!" << endl;
            return true;
        }
        cout << "You alive!" << endl;
        return false;
    }
};

int main()
{
    cout << endl;

    // accessing a class
    Player Arthur;

    Arthur.name = "Art";
    Arthur.health = 100;
    Arthur.exp = 500;

    Arthur.text("Hello");
    Arthur.is_dead();

    cout << endl;
    cout << endl;

    // Allocating a new object of type class
    Player *ptr{new Player};

    cout << "Memory address of the variable that is being pointed > " << ptr << endl;
    cout << "Memory address of the pointer > " << &ptr << endl;
    cout << endl;

    ptr->name = "Art";
    cout << "Name: : " << ptr->getname() << endl;
    ptr->health = 0;
    cout << "Health: " << ptr->gethealth() << endl;
    ptr->exp = 500;
    cout << "Exp: " << ptr->getexp() << endl;
    cout << endl;
    ptr->text("Hello");
    ptr->is_dead();
    cout << endl;
    cout << endl;

    // deallocating a object of a pointer
    delete ptr;
    ptr = nullptr;

    // Reallocating a new object of type class in a pointer
    ptr = new Player("Arthur", 40, 600);

    cout << "Name: : " << ptr->getname() << endl;
    cout << "Health: " << ptr->gethealth() << endl;
    cout << "Exp: " << ptr->getexp() << endl;
    cout << endl;
    ptr->text("Hello");
    ptr->is_dead();

    cout << endl;
    return 0;
}
