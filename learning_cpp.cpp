#include <iostream> // Preprocessors will process the code before the compilation.
#include <math.h>
using namespace std;
// "using namespace std;" means we don't need to write std:: because the compiler knows that we are already using it entirely.

int main(){
    // int main() is a function that returns some int number in the end of the execution of the program, if the
    // value returned is 0. than this means that there is no error in the program.
    cout << endl;

    int num {}; // This is where variables are stored.
    cout << "Type your favorite number between 1 and 10: ";
    cin >> num;
    cout << endl;
    cout << "Amazing that's my favorite too." << endl;
    cout << "or" << endl;
    cout << "No really!!?? " << num << " is my favorite number too!" << endl;
    cout << pow(num, 2) << endl;
    cout << pow(num, 0.5) << endl;
    cout << abs(num) << endl;
    cout << ceil(num) << endl;
    cout << floor(num) << endl;
    cout << "\n";

    // =================================================================================================
    // Size of type of variable
    std::cout << "size of const char: " << sizeof(const char) << " bytes" << std::endl;
    std::cout << "size of char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "size of char*: " << sizeof(char*) << " bytes" << std::endl;
    std::cout << "size of short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "size of long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "size of long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "size of short int: " << sizeof(short int) << " bytes" << std::endl;
    std::cout << "size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "size of long int: " << sizeof(long int) << " bytes" << std::endl;
    std::cout << "size of long long int: " << sizeof(long long int) << " bytes" << std::endl;
    std::cout << "size of unsigned int: " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "size of long double: " << sizeof(long double) << " bytes" << std::endl;
    std::cout << std::endl;
    // Minimum value for each type of variable
    std::cout << "minimun value of char: " << CHAR_MIN << std::endl;
    std::cout << "minimun value of int: " << INT_MIN << std::endl;
    std::cout << "minimun value of short: " << SHRT_MIN << std::endl;
    std::cout << "minimun value of long: " << LONG_MIN << std::endl;
    std::cout << "minimun value of long long: " << LLONG_MIN << std::endl;
    // =================================================================================================
    std::cout << std::endl;
    return 0;
}

/*
* Multiple line
* comment
*/
