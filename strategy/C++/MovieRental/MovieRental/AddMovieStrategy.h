#pragma once
#include "Movie.h"

class AddMovieStrategy 
{
public:
    virtual float AddMovie(const Movie& movie) = 0;
    virtual ~AddMovieStrategy() {}
};