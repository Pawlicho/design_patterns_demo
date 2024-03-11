using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MovieRental
{
    internal class RegularAddMovieStrategy : AddMovieStrategy 
    {
        /*! Every movie in this strategy costs defined amount of money */
        /* Premium content is restricted */
        public float AddMovie(Movie movie)
        {
            if (movie == null)
                throw new ArgumentNullException("Movie is not defined");
            else
            {
                if (movie.IsPremium)
                    return -1;
                else
                    return movie.Price;
            }
        }
    }
}
