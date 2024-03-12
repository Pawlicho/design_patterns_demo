#pragma once
#include "AddMovieStrategy.h"
#include <stdexcept>

class UnlimittedAddMovieStrategy : public AddMovieStrategy 
{
public:
    float AddMovie(const Movie& movie) override 
    {
        if (!&movie)
        {
            throw std::invalid_argument("Movie is not defined");
        }
        else 
        {
            /* Every movie in this subscription model is free */
            return 0;
        }
    }
};