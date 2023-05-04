#include <iostream>
using namespace std;

int main()
{
    // enum can be used for mapping.
    enum color
    {
        red = 1,
        green = 2,
        blue = 3
    };

    color screen_color{blue};

    switch (screen_color)
    {
    case 1:
        cout << "\nYou chose the first one: " << red;
        break;

    case 2:
        cout << "\nYou chose the second one: " << green;
        break;

    case 3:
        cout << "\nYou chose the third one: " << blue;
        break;

    default:
        cout << "\nYou didn't chose something.";
        break;
    }
    cout << endl;
    cout << endl;

    int num{};
    cout << "Memory address > " << &num;

    cout << endl;
    cout << endl;
    return 0;
}
