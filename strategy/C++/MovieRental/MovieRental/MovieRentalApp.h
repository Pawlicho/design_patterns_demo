#pragma once
#include "LibraryManager.h"

class MovieRentalApp 
{
private:
    LibraryManager manager;

public:
    MovieRentalApp() {}

    bool UpgradeSubscription() 
    {
        return manager.UpgradeSubscription();
    }

    bool DowngradeSubscription() 
    {
        return manager.DowngradeSubscription();
    }

    bool AddMovie(const std::string& title) 
    {
        return manager.AddMovie(title);
    }

    void PutMoney(float amount) 
    {
        manager.PutMoney(amount);
    }
};