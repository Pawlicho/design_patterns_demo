#pragma once
#include <vector>
#include <string>
#include "CanvaUnit.h"
#include "Coordinates.h"

class Canva 
{
private:
    uint32_t width;
    uint32_t height;
    std::vector<std::vector<CanvaUnit>> space;

public:
    Canva(uint32_t width_, uint32_t height_) : width(width_), height(height_) 
    {
        space.resize(height_);
        for (uint32_t i = 0; i < height; ++i) 
        {
            space[i].resize(width_);
            for (uint32_t j = 0; j < width_; ++j) 
            {
                space[i][j] = CanvaUnit();
            }
        }
    }

    CanvaUnit& GetUnit(Coordinates coord) 
    {
        return space[coord.Y][coord.X];
    }

    std::string GetCanvasRepresentation() 
    {
        std::string retVal;
        for (auto& row : space) 
        {
            for (auto& unit : row) 
            {
                if (unit.IsFilled()) 
                {
                    retVal += "X";
                }
                else 
                {
                    retVal += " ";
                }
            }
            retVal += "\n";
        }
        return retVal;
    }
};
