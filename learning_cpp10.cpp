#include <iostream>
#define pi 3.14159 // Declaring my own preprocessor derective

using std::cout;
using std::endl;

namespace scop
{
    int num{50};
}

void pointer_data(int *ptr)
{
    *ptr = 5;
}

int main()
{
    int num{100};

    // A three dimensions array that have three depths level, 4 rows and 5 columns
    unsigned arr[3][4][5]{0};

    for (unsigned d{}; d < 3; ++d)
    {
        for (unsigned r{}; r < 4; ++r)
        {
            for (unsigned c{}; c < 5; ++c)
            {
                cout << arr[d][r][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int *int_ptr{&scop::num};

    cout << "Value of num: " << scop::num << endl;
    cout << "Address of the variable num: " << &scop::num << endl;
    cout << "Value of pointer: " << *int_ptr << endl;
    cout << "Address of the variable pointer: " << int_ptr << endl;
    cout << endl;

    // Accessing my_namespace and using pi. A preprocessor derective process something to the real value before the compiler takes action
    cout << scop::num * pi << endl;
    pointer_data(int_ptr);
    cout << scop::num * pi << endl;
    cout << endl;
    cout << "Value of num: " << scop::num << endl;
    cout << "Address of the variable num: " << &scop::num << endl;
    cout << "Value of pointer: " << *int_ptr << endl;
    cout << "Address of the variable pointer: " << int_ptr << endl;
    cout << endl;

    // Allocating a new variable
    int_ptr = new int;
    *int_ptr = 8;

    cout << "Value of pointer: " << *int_ptr << endl;
    cout << "Address of the variable pointer: " << int_ptr << endl;
    cout << endl;

    // Deallocating the previous variable
    delete int_ptr;
    int_ptr = nullptr;

    cout << "Value of pointer: " << int_ptr << endl;

    cout << endl;

    return 0;
}
