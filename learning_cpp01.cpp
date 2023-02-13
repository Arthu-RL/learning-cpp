#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num{13};
    const int lower{10};
    const int upper{20};

    cout << boolalpha << endl;
    // cout << "Enter with a integer number, the bounds are between: " << lower << " and " << upper << endl;
    // cin >> num;

    bool test{};
    test = (num > lower && num < upper);
    cout << num << " is between " << lower << " and " << upper << ":" << test << endl;
    cout << endl;

    // Using some types of variables
    unsigned short exam_score {9};
    cout << "My exam score: " << exam_score << endl;
    long long people_earth {7'600'000'000};
    cout << "Number of people in the earth: " << people_earth << endl;
    long long distance_planet {9'543'900'000'000};
    cout << "Distance of a body: " << distance_planet << endl;
    float car_payment {509.67};
    cout << car_payment << endl;
    long double large_amount {2.7e120};
    cout << "Large double(float) number: " << large_amount << endl;
    bool x {false};
    cout << std::boolalpha;
    cout << "The variable x returns: " << x << endl;
    short value {30000};
    cout << value;
    cout << endl;
    cout << endl;
    return 0;
}
