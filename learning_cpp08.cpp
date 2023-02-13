#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    cout << endl;
    // Declaring && initializing pointers
    float num{5.6};

    cout << "Value > " << num << endl;
    cout << sizeof(num) << " bytes" << endl;
    cout << "Memory address > " << &num << endl;
    cout << endl;

    float *point{&num};

    cout << "Value pointed > " << *point << endl;
    cout << sizeof(point) << " bytes" << endl;
    cout << "Memory address of the variable that has been pointed > " << point << endl;
    cout << "Memory address of the pointer > " << &point << endl;
    cout << endl;

    *point = 200.6;
    cout << "Value > " << *point << endl;
    cout << "Memory address of the variable that has been pointered > " << point << endl;
    cout << endl;

    cout << "Value num now > " << num << endl;
    cout << "Memory address of num > " << &num << endl;

    // delete point

    cout << endl;
    cout << endl;

    vector<int> vec{22, 33};

    cout << "Value of vector > " << vec.at(1) << endl;
    cout << sizeof(vec) << " bytes" << endl;
    cout << "Memory address > " << &vec << endl;
    cout << endl;

    vector<int> *vec_ptr{&vec};

    cout << "Value pointed > " << (*vec_ptr).at(0) << endl;
    cout << sizeof(vec_ptr) << " bytes" << endl;
    cout << "Memory address of the variable that has been pointed > " << vec_ptr << endl;
    cout << "Memory address of the pointer > " << &vec_ptr << endl;
    cout << endl;

    int scores[]{23, 32, 80, 78, -50};
    int* score_ptr{scores};

    while (*score_ptr != -50){
        cout << *score_ptr << " ";
        score_ptr++;
    }

    cout << endl;
    cout << endl;
    return 0;
}
