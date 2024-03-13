#pragma once
#include "AddMovieStrategy.h"
#include <stdexcept>

class UnlimittedAddMovieStrategy : public AddMovieStrategy 
{
public:
    float AddMovie(const Movie& movie) override 
    {
        /* Every movie in this subscription model is free */
        return 0;
    }
};