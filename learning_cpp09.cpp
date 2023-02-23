#include <iostream>
#include <string>

using namespace std;

class MyClass
{
public:
    // Methods
    string reverse_word(string word)
    {

        for (int i{int(word.size())}; i > -1; i--)
        {
            str1 += word[i];
        }

        return str1;
    }

    void pyramid(string box)
    {
        string str1;
        string str2;
        int num1{0};

        for (int n{}; n < box.size(); ++n)
        {
            str2 += box[n];
            str1 += str2;
            for (int i{int(str2.size())}; i > -1; --i)
            {
                str1 += str2[i];
            }

            int num{(int(str1.size()) / 2)};

            str1.erase(num, 2);

            for (int v{}; v < (51 - num1); ++v)
            {
                cout << " ";
            }
            ++num1;

            cout << str1 << endl;
            str1.clear();
        }

        return;
    }

private:
    string str1;
};



int main()
{
    cout << endl;

    MyClass* ptr;

    ptr->pyramid("ARTHUR");

    cout << &ptr << endl;
    cout << ptr << endl;

    cout << endl;
    return 0;
}
