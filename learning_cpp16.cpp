#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    int health{};
    int xp{};
public:
    // Methods
    string getname(){ return name; };
    int gethealth(){ return health; };
    int getxp(){ return xp; };

    Player(string _name = "None", int _health = 0, int _xp = 0);

    // Copy constructor
    Player(const Player &src);

    // Destructor
    ~Player() { cout << "Destructor called for " << name << endl; };
};

Player::Player(string _name, int _health, int _xp) : name{_name}, health{_health}, xp{_xp} {
    cout << "Three args constructor." << endl;
}

Player::Player(const Player &src) : name{src.name}, health{src.health}, xp{src.xp} {
    cout << "Copy constructor made a copy of " << src.name << endl;
}

void display_player(Player p) {
    cout << "Name: " << p.getname() << endl;
    cout << "Health: " << p.gethealth() << endl;
    cout << "XP: " << p.getxp() << endl;
}

int main() {
    cout << "\n";
    Player empty;
    cout << "\n";
    display_player(empty);

    Player one{"TheOne"};
    display_player(one);

    Player Mage{"Medhiv", 60, 600};
    display_player(Mage);

    Player* ptr = &Mage;
    *ptr = {"WarGod Medhiv", 99, 999};

    cout << endl;
    return 0;
}
