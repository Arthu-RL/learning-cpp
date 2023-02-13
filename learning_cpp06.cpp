#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i{5};

    // ======================================================
    // Learning while syntax
    while (i >= 0)
    {
        if (i == 1)
        {
            cout << "Terminate.";
            break;
        }

        cout << i << " ";
        --i;

        if (i <= 5)
        {
            cout << "Continue" << endl;
            continue;
        }
    }

    cout << endl;

    int n{1};

    do
    {
        cout << n << " ";
        ++n;
    } while (n <= 5);
    // ======================================================

    cout << endl;
    cout << endl;

    // learning manipulation of std::string
    string s1{"Arthur"};
    string s2{s1, 0, 3};
    string s3{3, 's'};

    cout << "Hello " << s1 << endl;
    cout << "s1 length: " << s1.length() << endl;
    cout << "s1 index: " << s1[0] << " or " << s1.at(0) << endl;
    cout << "s1 substring: " << s1.substr(0, 3) << endl;
    cout << "Hello " << s2 << endl;

    for (size_t i{}; i < s1.length(); ++i)
    {
        cout << s1[i] << " ";
    }

    cout << endl;

    for (char i:s2){
        cout << i << " ";
    }
    return 0;
}
