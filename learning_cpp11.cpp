#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int *create_array(int size, int value = 0)
{
    int *storage{nullptr};
    storage = new int{size};

    for (int i{0}; i < size; ++i)
    {
        *(storage + i) = value;
    }

    return storage;
}

void display(const int *array, size_t size)
{
    for (size_t i{0}; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    cout << endl;
    int *arr{nullptr};
    size_t size{};
    int value{};

    cout << "\nHow many integers would you like to allocate? ";
    cin >> size;
    cout << "\nWhat value to be incialized would you like? ";
    cin >> value;

    arr = create_array(size, value);

    cout << endl;

    display(arr, size);

    arr = nullptr;

    cout << "\n";
    cout << "Deallocated pointer: " << arr << endl;
    cout << "\n---------------------------------------" << endl;

    vector<string> vec{"Aluneth", "Cronan", "Aleria"};

    for (auto v : vec)
    {
        v = "ZERO";
    }

    for (auto v : vec)
    {
        cout << v << " ";
    }
    cout << "\nThe string values of this vector didn't change." << endl;
    cout << "\n";

    for (auto &v : vec)
    {
        v = "ZERO";
    }

    for (auto v : vec)
    {
        cout << v << " ";
    }
    cout << "\n";
    cout << "\nThe string values of this vector changed because of the reference of a memory address, " << endl;
    cout << "Which change the value in the memory and not in the copy.";

    cout << endl;
    cout << endl;
    return 0;
}