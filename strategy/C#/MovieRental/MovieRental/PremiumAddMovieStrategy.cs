using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MovieRental
{
    internal class PremiumAddMovieStrategy : AddMovieStrategy 
    {
        /*! Every movie in this strategy costs defined amount of money */
        public float AddMovie(Movie movie)
        {
            if (movie == null)
                throw new ArgumentNullException("Movie is not defined");
            else
            {
                return movie.Price;
            }
        }
    }
}
