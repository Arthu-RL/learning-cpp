#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <math.h>

float train[][2]{
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8}
};

#define train_size sizeof(train) / sizeof(train[1])

float rand_float()
{
    return (float)rand() / (float)RAND_MAX;
}

float cost(float w, float b)
{
    float r = 0.0f;
    for (size_t i = 0; i < train_size; i++)
    {
        float x = train[i][0];
        float y = x * w + b;
        // std::cout << "actual " << y << " expected " << train[i][1] << '\n';
        float d = y - train[i][1];
        r += d * d;
    }
    r /= train_size;
    return r;
}

int main()
{
    // auto now = std::chrono::system_clock::now();
    auto now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    srand(now);
    float w = rand_float()*10.0f;
    float b = rand_float()*5.0f;
    float dx = 1e-3;
    float lrate = 1e-3;

    float dw = 0.0f;
    float db = 0.0f;

    std::cout << "w: " << w << ", lrate: " << lrate << ", dx: " << dx << "\n\n"; 

    while (cost(w, b) > 1e-5)
    {
        dw = (cost(w + dx, b) - cost(w, b))/dx;
        db = (cost(w, b + dx) - cost(w, b))/dx;

        std::cout << "weights: " << w << ", bias: " << b << ", dw: " << dw << ", db: " << db << '\n';
        w -= lrate*dw;
        b -= lrate*db;
    }

    std::cout << "weights: " << w << ", bias: " << b << ", dw: " << dw << ", db: " << db << '\n';
    std::cout << "cost: " << cost(w, b) << '\n';

    return 0;
}