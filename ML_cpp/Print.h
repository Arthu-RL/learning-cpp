#ifndef PRINT_H
#define PRINT_H
#include <iostream>

struct Colors
{
    const char *defaultColor = "\033[0m";
    const char *lightBlue =  "\033[36m";
    const char *pinkColor = "\033[35m";
    const char *DYellowColor = "\033[33m";
    const char *greenColor = "\033[32m";
    const char *redColor = "\033[31m";
} colors;

class Print
{   
public:
    template<typename... Args>
    void green(Args... args) {
        print(colors.greenColor);
        print(args...);
        print(colors.defaultColor);
    }

    template<typename... Args>
    void lblue(Args... args) {
        print(colors.lightBlue);
        print(args...);
        print(colors.defaultColor);
    }

    template<typename... Args>
    void yellow(Args... args) {
        print(colors.DYellowColor);
        print(args...);
        print(colors.defaultColor);
    }

    template<typename... Args>
    void pink(Args... args) {
        print(colors.pinkColor);
        print(args...);
        print(colors.defaultColor);
    }

    template<typename... Args>
    void red(Args... args) {
        print(colors.redColor);
        print(args...);
        print(colors.defaultColor);
    }

    template<typename... Args>
    void ok(Args... args) {
        std::cout << "[ ";
        green("OK");
        std::cout << " ] ";
        print(args...);
    }

    template<typename... Args>
    void error(Args... args) {
        std::cout << "[ ";
        red("ERROR");
        std::cout << " ] ";
        print(args...);
    }

private:
    template<typename Arg>
    void print(const Arg arg)
    {
        std::cout << arg;
    }

    template<typename First, typename... Args>
    void print(const First first, Args... args) 
    {
        std::cout << first; 
        print(args...);
    }
};

#endif