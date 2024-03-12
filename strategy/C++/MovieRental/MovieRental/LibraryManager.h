#pragma once
#include "RegularAddMovieStrategy.h"
#include "PremiumAddMovieStrategy.h"
#include "UnlimittedAddMovieStrategy.h"
#include <memory>
#include <vector>

class LibraryManager 
{
private:
    std::shared_ptr<AddMovieStrategy> strategy;
    std::vector<Movie> library;
    float saldo;

    static const float PREMIUM_SUBSCRIPTION_PRICE;
    static const float UNLIMITTED_SUBSCRIPTION_PRICE;

public:
    LibraryManager()
        : strategy(std::make_shared<RegularAddMovieStrategy>()), saldo(0) 
    {
        initializeLibrary();
    }

    std::vector<Movie>& GetLibrary() 
    {
        return library;
    }

    float GetSaldo() const 
    {
        return saldo;
    }

    void PutMoney(float value)
    {
        saldo += value;
    }

    bool AddMovie(const std::string& title) 
    {
        for (Movie& movie : library) 
        {
            if (movie.GetName() == title) 
            {
                float price = strategy->AddMovie(movie);
                if (price >= 0 && saldo >= price && !movie.GetIsBought()) 
                {
                    saldo -= price;
                    movie.SetIsBought(true);
                    return true;
                }
            }
        }
        return false;
    }

    bool UpgradeSubscription() {
        if (dynamic_cast<RegularAddMovieStrategy*>(strategy.get())) 
        {
            if (saldo >= PREMIUM_SUBSCRIPTION_PRICE) 
            {
                saldo -= PREMIUM_SUBSCRIPTION_PRICE;
                strategy = std::make_shared<PremiumAddMovieStrategy>();
                return true;
            }
        }
        else if (dynamic_cast<PremiumAddMovieStrategy*>(strategy.get())) 
        {
            if (saldo >= UNLIMITTED_SUBSCRIPTION_PRICE) 
            {
                saldo -= UNLIMITTED_SUBSCRIPTION_PRICE;
                strategy = std::make_shared<UnlimittedAddMovieStrategy>();
                return true;
            }
        }
        return false;
    }

    bool DowngradeSubscription() {
        if (dynamic_cast<PremiumAddMovieStrategy*>(strategy.get())) 
        {
            strategy = std::make_shared<RegularAddMovieStrategy>();
            return true;
        }
        else if (dynamic_cast<UnlimittedAddMovieStrategy*>(strategy.get())) 
        {
            strategy = std::make_shared<PremiumAddMovieStrategy>();
            return true;
        }
        return false;
    }

private:
    void initializeLibrary()
    {
        library.emplace_back("Fast and Furious 10", 5, false);
        library.emplace_back("Dune - part II", 10, true);
        library.emplace_back("Openheimer", 13, true);
        library.emplace_back("Anatomy of the fall", 11, false);
    }
};

const float LibraryManager::PREMIUM_SUBSCRIPTION_PRICE = 10;
const float LibraryManager::UNLIMITTED_SUBSCRIPTION_PRICE = 100;