using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MovieRental
{
    internal class UnlimittedAddMovieStrategy : AddMovieStrategy
    {
        /*! Every movie in this subscription model is free */
        public float AddMovie(Movie movie)
        {
            if (movie == null)
                throw new ArgumentNullException("Movie is not defined");
            else
            {
                return 0;
            }
        }
    }
}
