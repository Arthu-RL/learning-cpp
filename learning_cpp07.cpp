#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

int rand_num()
{
    srand(time(nullptr));

    int num{};
    int min{-4};
    int max{4};
    const int count{7};

    for (int i{}; i < count; ++i)
    {
        num = (rand() % max) + min;
        std::cout << "Random numbers: " << num << std::endl;
    }
    return 0;
}

double area_circle(double radius = 4.5)
{
    const double pi{3.14159};
    return (pi * pow(radius, 2));
}

void print_arr(int arr[], int size)
{
    for (int i{}; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

size_t factorial(unsigned n){
    if (n == 0){
        return 1;
    }
    return n * factorial(n-1);
}


// The address-of operator (&) can access the memory of the parameters, which means
// the parameter will not be a copy of a given parameter
void swapp(int &a, int &b){
    int temp{a};
    a = b;
    b = temp;
    std::cout << a << " and " << b << std::endl;
}

int main()
{
    std::cout << "RAND_MAX on my sytem: " << RAND_MAX << std::endl;

    rand_num();

    std::cout << std::endl;
    std::cout << area_circle() << std::endl;
    std::cout << std::endl;

    int arr[]{4, 5, 6, 9};
    print_arr(arr, 4);
    std::cout << std::endl;
    std::cout << std::endl;

    int num1{5}, num2{10};
    std::cout << num1 << " and " << num2 << std::endl;
    swapp(num1, num2);
    std::cout << num1 << " and " << num2 << std::endl;
    std::cout << std::endl;

    std::cout << factorial(5);

    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
