#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::vector;

class RNV
{
private:
    vector<float> vec;
    float num{};
    float max{};
    float min{};
    int iter{};

public:
    // Overload constructors
    RNV() { cout << "No args constructor" << endl; };

    RNV(vector<float> _vec) : vec{_vec}
    {
        vec_push_randn(vec, 5);
        print_vec();
        cout << endl;
        cout << "Max: " << max_num() << endl;
        cout << "Min: " << min_num() << endl;
    };

    RNV(vector<float> _vec, int _iter) : vec{_vec}, iter{_iter} { vec_push_randn(vec, iter); }

    // Destructor
    ~RNV()
    {
        cout << "Destructor called for vector ";
        print_vec();
    }

    // Methods
    void vec_push_randn(vector<float> _vec, int _iter)
    {
        vec = _vec;
        iter = _iter;
        srand(time(nullptr));

        for (int i{}; i < iter; i++)
        {
            num = static_cast<float>(rand() % 10) / 10;
            vec.push_back(num);
        }

        return;
    }

    void print_vec() const
    {
        for (float v : vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    float max_num()
    {
        for (float v : vec)
        {
            if (v > max)
            {
                max = v;
            }
        }
        return max;
    }

    float min_num()
    {
        min = vec[0];
        for (float v : vec)
        {
            if (v < min)
            {
                min = v;
            }
        }
        return min;
    }
};

int main()
{
    cout << endl;

    vector<float> v;

    RNV randnum{v};
    cout << endl;
    cout << endl;

    RNV *ptr{nullptr};
    ptr = new RNV{v, 10};

    ptr->print_vec();
    cout << endl;
    cout << "Max: " << ptr->max_num() << endl;
    cout << "Min: " << ptr->min_num() << endl;
    cout << "\n"
         << endl;

    delete ptr;
    ptr = nullptr;

    cout << endl;
    cout << endl;
    return 0;
}
