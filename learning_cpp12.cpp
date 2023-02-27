#include <iostream>
#include <string>

class Player
{
public:
    // Default constructor
    Player()
    {
        std::cout << "No args constructor called" << std::endl;
    }

    Player(std::string _name) : name(_name) {}

    Player(std::string _name, int _health, int _xp) : name(_name), health(_health), xp(_xp)
    {
        std::cout << "Three args constructor called" << std::endl;
    }

    //  Destructor
    ~Player()
    {
        std::cout << "Destructor called for " << name << std::endl;
    }

    // Methods
    void get_name() { std::cout << "I am " << name << ", your hero!" << std::endl; }
    void get_health() { std::cout << ((health > 50) ? "High health" : "Low health") << std::endl; }
    void get_xp() { std::cout << ((xp > 500) ? "High level" : "Low level") << std::endl; }

    void set_player(std::string _name, int _health, int _xp)
    {
        name = _name;
        health = _health;
        xp = _xp;
        get_name();
        get_health();
        get_xp();
        std::cout << std::endl;
        std::cout << std::endl;
    }

private:
    // Atributes
    std::string name;
    int health{};
    int xp{};
};

int main()
{
    std::cout << std::endl;

    // Constructor overloading
    Player Warrior;
    Warrior.set_player("Cronan", 95, 400);
    Player Warlock;
    Warlock.set_player("Guldann", 30, 1200);
    Player Paladin;
    Paladin.set_player("Uther", 70, 650);
    std::cout << std::endl;
    // Destructor deleting these allocations.

    // Studying more pointers
    // Allocating pointer of type class
    Player *ptr{nullptr};
    ptr = new Player("Garona", 60, 800);

    ptr->get_name();
    ptr->get_health();
    ptr->get_xp();
    std::cout << std::endl;
    std::cout << ptr << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // Deallocating pointer
    delete ptr;
    ptr = nullptr;

    // Allocating a new type class Player inside the pointer
    // Note that the memory address of "ptr" is not changing, this happens because the type class Player is the same in this pointer, as declared above "Player *ptr{nullptr};".
    ptr = new Player("Hunter", 40, 1000);

    ptr->get_name();
    ptr->get_health();
    ptr->get_xp();
    std::cout << std::endl;
    std::cout << ptr << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
