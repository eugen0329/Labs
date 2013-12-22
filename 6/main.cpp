#include <cstdlib>
#include <iostream>
#include "products.h"
#include "tree.h"

using namespace std;

int main()
{
    //int number;
    Shop walmart;
    // {{{
    //Bucket bucket;
    //Bank bank;

    //cout << "Set the bank score" << endl;
     
    //bank.setScore(getNaturalNumber());

    
    //while(true) {


    //    cout << "The availablity of the shop" << endl << endl;
    //    walmart.showAvailablity();
    //    cout << "Set the Numbers of the products you want to buy(0 to exit)" << endl;
    //    
    //    while(true) {

    //        number = getNaturalNumber();
    //        if (number == 0) {
    //            break;
    //        } 


    //        if (walmart.checkKey(number)) {
    //            cout << "Wrong number" << endl;
    //        } else {
    //            cout << "Added:" << endl << walmart.getProductByNumber(number);
    //            bucket.addToTheBucket(walmart.getProductByNumber(number));
    //        }
    //    }

    //    bank.checkAccount(bucket.getSum());
    //    if (bucket.getSum() != 0) {
    //        cout << "Do you want to make a purchase??" << endl;
    //        if(confirm_choice()) {
    //            bank.makeAPurchase(bucket.getSum());
    //        }
    //    }

    //    bucket.freeBucket();
    //    cout << "Do you want to continue buying??" << endl;
    //    if(!(confirm_choice()) ) {
    //        break;
    //    }
    //    
    //}

    //bank.checkAccount();
    // }}}
    walmart.showAvailablity();
    return 0;
}

