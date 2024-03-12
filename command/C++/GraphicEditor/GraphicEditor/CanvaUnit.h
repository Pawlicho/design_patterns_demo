#pragma once
#include <iostream>

class CanvaUnit 
{
private:
    bool isFilled;

public:
    CanvaUnit() : isFilled(false) 
    {}

    bool IsFilled() const 
    {
        return isFilled;
    }

    void Fill() 
    {
        isFilled = true;
    }

    void Wipe() 
    {
        isFilled = false;
    }
};
