using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MovieRental
{
    internal class MovieRentalApp
    {
        private LibraryManager manager;

        public MovieRentalApp()
        {
            manager = new LibraryManager();

            /* Initializing library manager with some movies */
            /* This is just for testing and should be done in different */
            /* E.g. Factory class should be defined and its object added here */
            /* In that way we could add movies to database through simple interface */

            manager.Library.Add(new Movie("Fast and Furious 10", 5, false));
            manager.Library.Add(new Movie("Dune - part II", 10, true));
            manager.Library.Add(new Movie("Openheimer", 13, true));
            manager.Library.Add(new Movie("Anatomy of the fall", 11, false));
        }

        public bool UpgradeSubscribtion()
        {
            return manager.UpgradeSubscribtion();
        }

        public bool DowngradeSubscribtion()
        {
            return manager.DowngradeSubscribtion();
        }

        public bool AddMovie(String title)
        {
            return manager.AddMovie(title);
        }

        public void PutMoney(float  amount) 
        {
            manager.Saldo += amount;
        }
    }
}
