using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MovieRental
{
    internal class Movie
    {
        private String name;
        private float price;
        private bool isBought;
        private bool isPremium;
        public Movie(String name_="", float price_=0, bool isPremium_=false)
        {
           name = name_;
            price = price_;
            isPremium = isPremium_;
            isBought = false;
        }

        public String Name
        {
            get { return name; }
        }
        public float Price
        {
            get { return price; }
        }
        public bool IsBought
        {
            get { return isBought; }
            set { isBought = value; }
        }
        public bool IsPremium
        {
            get { return isPremium; }
        }
    }
}
