#include <iostream>
#include <string>

using namespace std;

class Player
{

private:
    string name;
    int health{0};
    int xp{0};

public:
    // Overloaded constructors
    Player();
    Player(string _name);
    Player(string _name, int _health, int _xp);
};

// Delegating Construtors calling the three args constructor

Player::Player() : Player{"None", 0, 0}
{
    cout << "No args constructor" << endl
         << endl;
}

Player::Player(string _name) : Player{_name, 0, 0}
{
    cout << "One args constructor" << endl
         << endl;
}

Player::Player(string _name, int _health, int _xp) : name{_name}, health{_health}, xp{_xp}
{
    cout << _name << " has " << _health << " of health and " << _xp << " of xp." << endl;
}

int main()
{
    cout << "\n";
    Player empty;
    Player one{"TheOne"};
    Player Mage{"Medhiv", 60, 600};

    cout << "\n";
    Player *ptr = &Mage;
    *ptr = {"Dark Medhiv", 99, 999};

    return 0;
}
