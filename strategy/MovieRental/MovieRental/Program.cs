namespace MovieRental
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("MovieRentalApp for strategy design pattern demo");

            var app = new MovieRentalApp();

            Console.WriteLine("trying to add movie that does not exist: {0}", app.AddMovie(""));
            Console.WriteLine("trying to add movie that does exist but saldo is to low: {0}", app.AddMovie("Fast and Furious 10"));
            app.PutMoney(5);
            Console.WriteLine("trying to add movie that does exist, saldo is enaugh and set correct subscription plan: {0}", app.AddMovie("Fast and Furious 10"));
            app.PutMoney(10);
            Console.WriteLine("trying to add premium movie that does exist, saldo is enaugh and set incorrect subscription plan: {0}", app.AddMovie("Dune - part II"));
            app.PutMoney(10);
            Console.WriteLine("trying to upgrade subscription: {0}", app.UpgradeSubscribtion());
            Console.WriteLine("trying to add movie that does exist, saldo is enaugh and set correct subscription plan: {0}", app.AddMovie("Dune - part II"));
            app.PutMoney(100);
            Console.WriteLine("trying to upgrade subscription: {0}", app.UpgradeSubscribtion());
            Console.WriteLine("trying to add premium movie that does exist, unlimitted plann saldo is 0: {0}", app.AddMovie("Openheimer"));
            Console.WriteLine("trying to add movie that does exist, unlimitted plann saldo is 0: {0}", app.AddMovie("Anatomy of the fall"));
            Console.WriteLine("trying to add movie that does exist and is already bought {0}", app.AddMovie("Anatomy of the fall"));
        }
    }
}