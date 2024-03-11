using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace MovieRental
{
    internal class LibraryManager
    {
        private AddMovieStrategy strategy;
        private List<Movie> library;
        private float saldo;

        private const float PREMIUM_SUBSCRIPTION_PRICE = 10;
        private const float UNLIMITTED_SUBSCRIPTION_PRICE = 100;

        public LibraryManager()
        {
            strategy = new RegularAddMovieStrategy();
            library = new List<Movie>();
            saldo = 0;
        }

        public List<Movie> Library
        {
            get { return library; }
            set { library = value; }
        }

        public float Saldo
        {
            get { return saldo; }
            set { saldo = value; }
        }

        public bool AddMovie(String title)
        {
            bool retVal = false;

            /* Search if movie exists in library */
            foreach (Movie movie in library) 
            {
                if (movie.Name == title) 
                {
                    var price = strategy.AddMovie(movie);
                    /* If movie is not in library and can be bought */
                    /* Decrease saldo */
                    if (price >= 0 && saldo >= price && !(movie.IsBought)) 
                    {
                        saldo -= price;
                        movie.IsBought = true;
                        retVal = true;
                    }
                }
            }
            
            return retVal;
        }

        public bool UpgradeSubscribtion()
        {
            var retVal = true;
            if (strategy is  RegularAddMovieStrategy)
            {
                if (saldo >= PREMIUM_SUBSCRIPTION_PRICE)
                {
                    saldo -= PREMIUM_SUBSCRIPTION_PRICE;
                    strategy = new PremiumAddMovieStrategy();
                }
                else
                {
                    retVal = false;
                }
            }
            else if (strategy is PremiumAddMovieStrategy)
                if (saldo >= UNLIMITTED_SUBSCRIPTION_PRICE)
                {
                    saldo -= UNLIMITTED_SUBSCRIPTION_PRICE;
                    strategy = new UnlimittedAddMovieStrategy();
                }
                else
                {
                    retVal = false;
                }
            else
                retVal = false;

            return retVal;
        }

        public bool DowngradeSubscribtion()
        {
            var retVal = true;
            if (strategy is PremiumAddMovieStrategy)
                strategy = new RegularAddMovieStrategy();
            else if (strategy is UnlimittedAddMovieStrategy)
                strategy = new PremiumAddMovieStrategy();
            else
                retVal = false;

            return retVal;
        }
    }


}
