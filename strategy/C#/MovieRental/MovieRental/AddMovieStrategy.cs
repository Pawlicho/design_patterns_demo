using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MovieRental
{
    internal interface AddMovieStrategy
    {
        public float AddMovie(Movie movie);
    }
}
