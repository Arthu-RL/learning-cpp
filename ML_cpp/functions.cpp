#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP

#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
#include <chrono>

#include "Print.h"

static Print p;

// typedef struct
// {
//     // OR gate inputs
//     std::vector<std::vector<float>> gate{
//         {0, 0, 0},
//         {1, 0, 1},
//         {0, 1, 1},
//         {1, 1, 1}
//     };

//     std::string name = "OR";
// } OR;

// typedef struct
// {
//     // AND gate inputs
//     std::vector<std::vector<float>> gate{
//         {0, 0, 0},
//         {1, 0, 0},
//         {0, 1, 0},
//         {1, 1, 1}
//     };

//     std::string name = "AND";
// } AND;

// typedef struct
// {
//     // NAND gate inputs
//     std::vector<std::vector<float>> gate{
//         {0, 0, 1},
//         {1, 0, 1},
//         {0, 1, 1},
//         {1, 1, 0}
//     };

//     std::string name = "NAND";
// } NAND;

float sigmoid(float x)
{
    return 1.f / (1.f + expf(-x));
}

float rand_float()
{
    return (float)rand() / (float)RAND_MAX;
}

template<typename Type>
void display_bivector(std::vector<std::vector<Type>> v) {
    for (unsigned i=0; i < v.size(); ++i) {
        for (unsigned j=0; j < v[i].size(); ++j) {
            std::cout << v[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

class GATE
{
public:
    // float or_w1=0.0f;
    // float or_w2=0.0f;
    // float or_b=0.0f;

    // float and_w1=0.0f;
    // float and_w2=0.0f;
    // float and_b=0.0f;

    // float nand_w1=0.0f;
    // float nand_w2=0.0f;
    // float nand_b=0.0f;

    std::vector<std::vector<float>> weights = {
        {0.148414, 1.99136, 1.64218}, 
        {0.874276, 0.307285, 1.11671}, 
        {0.160735, 0.374279, 2.96624}
    };

    GATE()
    {
        auto now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        srand(now);

        // Inicialize the weights
        float change = 1.0f;
        for (unsigned i=0; i < weights.size(); ++i){
            change = 0.0f;
            for (unsigned j=0; j < weights[i].size(); ++j) {
                if (change == 0.0f) { change++; }
                weights[i][j] = rand_float()*change;
                change += i+j+1;
            }
        }
    };

    // XOR gate inputs
    std::vector<std::vector<float>> gate {
        {0, 0, 0},
        {1, 0, 1},
        {0, 1, 1},
        {1, 1, 0}
    };

    void display_weights()
    {
        p.pink("Vector of weights: \n");
        for (unsigned i=0; i < weights.size(); ++i){
            for (unsigned j=0; j < weights[i].size(); ++j) {
                p.yellow(weights[i][j], ", ");
            }
            std::cout << '\n';
        }
    };

private:
    std::string name = "GATE(or, and, xor))";
};

float forward(std::vector<std::vector<float>> weights, float x1, float x2)
{
    // hidden layers 
    float or_output = sigmoid(weights[0][0] * x1 + weights[0][1] * x2 + weights[0][2]);
    float nand_output =  sigmoid(weights[1][0] * x1 + weights[1][1] * x2 + weights[1][2]);

    // last layer with single neuron computation 
    return sigmoid(weights[2][0] * or_output*or_output + weights[2][1] * nand_output + weights[2][2]);
}

// Cost function
float cost(std::vector<std::vector<float>> gate, std::vector<std::vector<float>> weights)
{
    float r = 0.0f;
    for (size_t i=0; i < gate.size(); ++i)
    {
        float x1 = gate[i][0];
        float x2 = gate[i][1];
        float y = forward(weights, x1, x2);
        float d = y - gate[i][2];
        r += d*d;
    }
    r /= gate.size();
    return r;
}

template<typename GateType>
void diff_weights(GateType &_XOR, float lrate, float dx) {
    std::vector<std::vector<float>> weights = _XOR.weights;
    std::vector<std::vector<float>> dws;
    
    for (unsigned i=0; i < weights.size(); ++i) {
        dws.push_back({0.0f, 0.0f, 0.0f});
        for (unsigned j=0; j < weights[i].size(); ++j) {
            float c = cost(_XOR.gate, weights); 
            float saved = weights[i][j];

            weights[i][j] += dx;

            float dw = (cost(_XOR.gate, weights) - c) / dx;
            dws[i][j] = dw;

            weights[i][j] = saved;
        }
    }

    // std::cout << "_XOR.weights: " << '\n';
    // display_bivector(_XOR.weights);

    // std::cout << "weights: " << '\n';
    // display_bivector(weights);

    // std::cout << "dws: " << '\n';
    // display_bivector(dws);

    for (unsigned i=0; i < weights.size(); ++i) {
        for (unsigned j=0; j < weights[i].size(); ++j) {
            _XOR.weights[i][j] -= lrate*dws[i][j];
        }
    }
}

void test_model(std::vector<std::vector<float>> gate, std::vector<std::vector<float>> weights, std::string name)
{   
    p.pink("Testing model ", name, "...", '\n');
    for (size_t i=0; i < gate.size(); ++i)
    {
        float x1 = gate[i][0];
        float x2 = gate[i][1];
        float expected = gate[i][2];

        float pred = forward(weights, x1, x2);
        // std::cout << "DEBUG: " << "sin_pred: " << pred << ", pred: " << x1*w1 + x2*w2 + b << '\n';

        // pred = round(pred);

        p.lblue(x1, " | ", x2, "; prediction: ", pred, "; expected: ", expected, '\n');
    }

    if (cost(gate, weights) > 0.001) {
        p.error("Treinamento do modelo ", name, " foi um fracasso");
        exit(EXIT_FAILURE);
    }

    p.ok(name, " trained successfully\n\n");
}

#endif