#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<float>> vec{
        {4.5, 6.8, 3.6},
        {5.8, 9.8, 2.1}
    };

    vec.push_back({0.6, 1.7, 5.2});
    vec.push_back({4.7, 6.3});

    for (unsigned rows{}; rows < vec.size(); ++rows)
    {
        for (unsigned cols{}; cols < vec[rows].size(); ++cols)
        {
            cout << vec[rows][cols] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int scores[]{15, 27, 33, 41};
    for (unsigned i : scores)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

    vector<double> temps{40.64, 55.43, 33.79, 26.87};
    double sum{};
    unsigned count{};
    double average{};

    for (auto t : temps)
    {
        sum += t;
        ++count;
    }

    average = sum / count;
    cout << "sum " << sum << ", count " << count << ", average temperature " << average;

    cout << endl;
    cout << endl;
    return 0;
}
