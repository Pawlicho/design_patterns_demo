#pragma once
#include <iostream>
#include <string>

class Movie 
{
private:
    std::string name;
    float price;
    bool isBought;
    bool isPremium;

public:
    Movie(std::string name_ = "", float price_ = 0, bool isPremium_ = false)
        : name(name_), price(price_), isPremium(isPremium_), isBought(false) 
    {
    }

    std::string GetName() const
    {
        return name;
    }

    float GetPrice() const
    {
        return price;
    }

    bool GetIsBought() const
    {
        return isBought;
    }

    void SetIsBought(bool value)
    {
        isBought = value;
    }

    bool GetIsPremium() const
    {
        return isPremium;
    }
};