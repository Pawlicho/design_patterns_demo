#pragma once
#include "AddMovieStrategy.h"
#include <stdexcept>

class RegularAddMovieStrategy : public AddMovieStrategy 
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
    }
};
