#include <array>
#include <iostream>
#include <cmath> 
#include <vector>

#define WITHOUT_NUMPY
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

//Carpet Contents are Squares
class Square
{
public:
    //Square Constructor
    Square(int remainingIterations, double x, double y, double size)
    {
        //Prop Assignment
        this->x = x;
        this->y = y;
        this->size = size;

        MarkDown();

        Build(remainingIterations);

    }

    ~Square()
    {
        delete this;
    }

private:
    //Alligned to Lower Left Corner
    double x, y;
    double size;

    //Next Generation Squares
    Square* squares[8];

    //Plotting Procedure
    //Actually, plotting of white center square is enough
    void MarkDown()
    {
        //White Segment Plotting
        double segmentSize = size / 3;
        plt::fill_between(
                std::vector<double>{x + segmentSize    , x + segmentSize * 2}, 
                std::vector<double>{y + segmentSize * 2, y + segmentSize * 2}, 
                std::vector<double>{y + segmentSize    , y + segmentSize    },
                {{"color", "w"}} );
    }

    //New Generation Building Procedure
    void Build(int remainingIterations)
    {
        if(remainingIterations) 
        {
            int numberNew = 0;
            for(int yNew = 0; yNew < 3; ++yNew)
            {
                for(int xNew = 0; xNew < 3; ++xNew)
                {
                    //We skip creation of centre square
                    if(xNew == 1 && yNew == 1) { xNew++; }
                    squares[numberNew] = new Square(remainingIterations - 1,
                           this->x + xNew * size / 3,
                           this->y + yNew * size / 3,
                           size / 3);
                    numberNew++;
                }
            }
        }

    }
};
