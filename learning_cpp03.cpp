#include <iostream>

int main()
{
    int num1{45}, num2{50};
    int total_of_objects{2};
    double average{0};

    average = static_cast<double>((num1 + num2)) / total_of_objects;
    std::cout << average << std::endl;

    const int min{10};
    const int max{100};

    if (average >= min && average <= max)
    {
        if (average > (min + 40))
        {
            std::cout << "That's a high average." << std::endl;
        }
        else if (average < (max - 50))
        {
            std::cout << "Tha't a low average." << std::endl;
        }
        std::cout << average << " is between 10 and 100." << std::endl;
    }


    if (average == min || average == max)
    {
        std::cout << average << " is right on a boundary." << std::endl;
    }
    else if (average == min)
    {
        std::cout << average << " is on the boundary min." << std::endl;
    }
    else if (average == max)
    {
        std::cout << average << " is on the boundary max." << std::endl;
    }
    else
    {
        std::cout << average << " is not on a bondary." << std::endl;
    }

    // Conditional operator
    int score{};
    std::cin >> score;

    std::cout << ((score > 90) ? "Excelent" : "Good") << std::endl;
    std::cout << ((score % 2 == 0) ? "is even" : "is odd");

    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
