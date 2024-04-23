#pragma once
#include <string>
#include <map>
#include "OrderBookEntry.h"

class Wallet
{
    public:
        Wallet();
        /** insert currency to the wallet */
        void insertCurrency(std::string type, double amount);
        /** remove currency from the wallet */
        bool removeCurrency(std::string type, double amount);
        /** check if the wallet contains this much currency or more */
        bool containsCurrency(std::string type, double amount);
        /** generate a string representation of the wallet */
        std::string toString();
        /** check if the wallet can cope with this ask or bid */
        bool canFulfillOrder(OrderBookEntry order);
        /** Return true if the Wallet contains sufficient funds to fulfill order.*/
        void processSale(OrderBookEntry& sale);

        friend std::ostream& operator<<(std::ostream& os, Wallet& wallet);
    private:
        std::map<std::string,double> currencies;
};