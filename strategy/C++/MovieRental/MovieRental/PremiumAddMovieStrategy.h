#pragma once
#include "AddMovieStrategy.h"
#include <stdexcept>

class PremiumAddMovieStrategy : public AddMovieStrategy {
public:
    float AddMovie(const Movie& movie) override 
    {
        /* Every movie in this strategy costs the defined amount of money */
        return movie.GetPrice();
    }
};