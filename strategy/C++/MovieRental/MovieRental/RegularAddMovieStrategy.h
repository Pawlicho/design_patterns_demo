#pragma once
#include "AddMovieStrategy.h"
#include <stdexcept>

class RegularAddMovieStrategy : public AddMovieStrategy 
{
public:
    float AddMovie(const Movie& movie) override 
    {
        if (movie.GetIsPremium()) {
            /* Premium content is restricted */
            return -1;
        }
        else
        {
            /* Every movie in this strategy costs the defined amount of money */
            return movie.GetPrice();
        }
    }
};
