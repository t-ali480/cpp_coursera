#include "Wallet.h"
#include "CSVReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

Wallet::Wallet()
{

}

void Wallet::insertCurrency(std::string type, double amount)
{   
    if (amount > 0)
    {
        double balance = amount;
        currencies[type] += balance;
        for (const auto& pair : currencies)
        {
            std::cout << pair.first << ": " << pair.second << std::endl;    
        }    
    }
    else
    {
        std::cout << "Bad insert. Enter positive integer" << std::endl; 
    }     
}

bool Wallet::removeCurrency(std::string type, double amount)
{
    double balance;
    
    if (amount < 0)
    {
        return false;
    }
    if (currencies.count(type) == 0)
    {
        return false;
    }
    else
    {
        if (containsCurrency(type, amount) > amount)
        {
            currencies[type] -= amount;
            return true;
        }
        else
        {
            return false; 
        }
    }
}

bool Wallet::containsCurrency(std::string type, double amount)
{
    double balance;
    
    if (currencies.count(type) == 0)
    {
        balance = 0;
        return false;
    }
    else
    {
        balance = currencies[type];
        return true;
    }
    balance += amount;
    currencies[type] = balance;
}

std::string Wallet::toString()
{
    std::string s;
    for (std::pair<std::string,double> pair : currencies)
    {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + ": " + std::to_string(amount) + "\n";
    }
    return s;
}

/* */// call it with std::cout << wallet << std::endl; in main.cpp
std::ostream& operator<<(std::ostream& os, Wallet& wallet)
{
    os << wallet.toString();
    return os;
}

bool Wallet::canFulfillOrder(OrderBookEntry order)
{   
    std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
    //ask
    if (order.orderType == OrderBookType::ask)
    {
        double amount = order.amount;
        std::string currency = currs[0];
        return containsCurrency(currency, amount);
    }
    //bid
    if (order.orderType == OrderBookType::bid)
    {
        double amount = order.amount * order.price;
        std::string currency = currs[1];
        return containsCurrency(currency, amount);
    }
    return false;
}

void Wallet::processSale(OrderBookEntry& sale)
{
    std::vector<std::string> currs = CSVReader::tokenise(sale.product, '/');
    
    // ask
    if (sale.orderType == OrderBookType::asksale)
    {
        double outgoingAmount = sale.amount;
        std::string outgoingCurrency = currs[0];
        double incomingAmount = sale.amount * sale.price;
        std::string incomingCurrency = currs[1];
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
    // bid
    if (sale.orderType == OrderBookType::bidsale)
    {
        double incomingAmount = sale.amount;
        std::string incomingCurrency = currs[0];
        double outgoingAmount = sale.amount * sale.price;
        std::string outgoingCurrency = currs[1];
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
}