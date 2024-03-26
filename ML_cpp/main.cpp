#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <math.h>
#include <vector>
#include <memory>

// #include "Print.h"

#include "functions.cpp"


int main()
{
    std::unique_ptr<Print> p = std::make_unique<Print>();
    GATE _GATE;

    _GATE.display_weights();

    p->yellow("Trainning XOR...", '\n');

    float lrate = 0.01;

    for (size_t i=0; i < 1000*500; ++i)
    {
        diff_weights(_GATE, lrate, 0.01);
        p->yellow("cost: ", cost(_GATE.gate, _GATE.weights), '\n');

        // if (i == 500000) {
        //     lrate = 0.001;
        // }
    }

    p->ok("Models Trained\n");

    test_model(_GATE.gate, _GATE.weights, "XOR");

    return 0;   
}