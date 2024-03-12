#include <iostream>
#include "MovieRentalApp.h"

int main()
{
    std::cout << "MovieRentalApp for strategy design pattern demo" << std::endl;

    MovieRentalApp app;

    std::cout << "trying to add movie that does not exist: " << std::boolalpha << app.AddMovie("") << std::endl;
    std::cout << "trying to add movie that does exist but saldo is too low: " << std::boolalpha << app.AddMovie("Fast and Furious 10") << std::endl;
    app.PutMoney(5);
    std::cout << "trying to add movie that does exist, saldo is enough, and set correct subscription plan: " << std::boolalpha << app.AddMovie("Fast and Furious 10") << std::endl;
    app.PutMoney(10);
    std::cout << "trying to add premium movie that does exist, saldo is enough, and set incorrect subscription plan: " << std::boolalpha << app.AddMovie("Dune - part II") << std::endl;
    app.PutMoney(10);
    std::cout << "trying to upgrade subscription: " << std::boolalpha << app.UpgradeSubscription() << std::endl;
    std::cout << "trying to add movie that does exist, saldo is enough, and set correct subscription plan: " << std::boolalpha << app.AddMovie("Dune - part II") << std::endl;
    app.PutMoney(100);
    std::cout << "trying to upgrade subscription: " << std::boolalpha << app.UpgradeSubscription() << std::endl;
    std::cout << "trying to add premium movie that does exist, unlimited plan saldo is 0: " << std::boolalpha << app.AddMovie("Openheimer") << std::endl;
    std::cout << "trying to add movie that does exist, unlimited plan saldo is 0: " << std::boolalpha << app.AddMovie("Anatomy of the fall") << std::endl;
    std::cout << "trying to add movie that does exist and is already bought: " << std::boolalpha << app.AddMovie("Anatomy of the fall") << std::endl;

    return 0;
}