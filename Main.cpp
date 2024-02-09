#ifndef UTILITY
#define UTILITY
#include <array>
#include <iostream>
#include <cmath> 
#include <vector>
#endif

#include "square.h"


class Carpet
{
public:
    //Carpet Constructor
    Carpet()
    {
        SetDepth();
        MarkDown();
        Build();
    }

    ~Carpet()
    {
        delete this;
    }

private:
    //Size of Carpet (Only affects coordinates and resolution)
    const double size = 100;

    //Amount of Generations
    int depth;

    //The first square
    Square *mainSquare;

    //Amount of Generations Input
    void SetDepth()
    {
        std::cout << "Enter depth: ";
        std::cin >> depth;
        return;
    }

    //Recursive building start
    void Build()
    {
        mainSquare = new Square(depth - 1,
                0,
                0,
                size);
        return;
    }

    //Blue Field Markdown
    void MarkDown()
    {
        plt::fill_between(
                std::vector<double>{0   , size}, 
                std::vector<double>{size, size}, 
                std::vector<double>{0   , 0   },
                {{"color", "c"}} );

    }

};

int main()
{
    Carpet carpet;

    plt::axis("scaled");
//    plt::save("Image.png", 100);
    plt::show();

    return 0; 
}

