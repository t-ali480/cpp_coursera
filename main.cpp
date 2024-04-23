#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"

int main()
{   
    // Wallet wallet{};
    // wallet.insertCurrency("BTC", 1.5);
    // std::cout << "Wallet should contain 1.5 BTC now" << std::endl;
    // std::cout << wallet << std::endl;
    // bool result = wallet.containsCurrency("BTC", 1.5);
    // std::cout << "Result should be true " << result << std::endl;
    // result = wallet.removeCurrency("BTC", 2.0);
    // std::cout << "Result should be false " << result << std::endl;
    // result = wallet.removeCurrency("BTC", 1.0);
    // std::cout << "Result should be true " << result << std::endl;
    MerkelMain app{};
    app.init();
    //CSVReader::readCSV("20200317.csv");

}






//     std::vector<OrderBookEntry> orders;

//     orders.push_back(  OrderBookEntry{1000, 
//                           0.02, 
//                         "2020/03/17 17:01:24.884492", 
//                         "BTC/USDT", 
//                         OrderBookType::bid}    );

//     orders.push_back(  OrderBookEntry{2000, 
//                           0.02, 
//                         "2020/03/17 17:01:24.884492", 
//                         "BTC/USDT", 
//                         OrderBookType::bid}    );
        

//    // std::cout << "The price is " << orders[1].price << std::endl;

//     for (OrderBookEntry& order : orders)
//     {
//         std::cout << "The price is " << order.price << std::endl;
//     }

//     for (unsigned int i = 0; i < orders.size() ; ++i)
//     {
//         std::cout << "The price is " << orders[i].price << std::endl;
//     }

//     for (unsigned int i = 0; i < orders.size() ; ++i)
//     {
//         std::cout << "The price is " << orders.at(i).price << std::endl;
//     }




