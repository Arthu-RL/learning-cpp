#include <iostream>
#include <ostream>
#include <vector>

using std::vector;

int main()
{
    // Creating a array
    int list[]{1, 2, 3, 4, 5, 6};
    std::cout << list[1] << std::endl;
    int arr [3][4] {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    std::cout << arr[1][2] << std::endl;
    std::cout << std::endl;
    
    // Creating a vector. Vectors are dynamic, their size are not fixed.
    vector<int> test_score{11, 22};
    std::cout << test_score[1] << std::endl;
    // std::cin >> test_score.at(0);
    std::cout << test_score.at(0) << std::endl;
    test_score.push_back(100);
    std::cout << test_score.at(2) << std::endl;
    test_score.pop_back();
    test_score.clear();
    std::cout << test_score[0] << std::endl;
    std::cout << std::endl;
    // std::cout << test_score.at(2) << std::endl;

    vector <vector<int>> vec2d;
    vec2d.push_back({1, 2, 3});
    vec2d.push_back({4, 5, 6});
    vec2d.push_back({7, 8, 9});

    std::cout << vec2d.at(1).at(2) << std::endl;
    std::cout << vec2d[2][1] << std::endl;
    std::cout << vec2d.size() << std::endl;
    std::cout << std::endl;
    return 0;
}
