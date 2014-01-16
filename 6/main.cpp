#include <cstdlib>
#include <iostream>
#include "products.h"
#include "tree.h"

using namespace std;

int main()
{
    int number;
    Shop walmart;
    Bucket bucket;
    Bank bank;

    cout << "Set the bank score" << endl;
    
    bank.setScore(getNaturalNumber());

    
    while(true) {
        cout << "The availablity of the shop" << endl << endl;
        walmart.showAvailablity();
        
        while(true) {
            cout << "Set the number of the product you want to buy(0 to exit)" << endl;
            number = getNaturalNumber();
            if(number == 0) {
                break;
            }
            try {
                bucket.addToTheBucket(walmart.getProductByNumber(number));
                cout << "adding..." << endl;
            }
            catch(WrongData exception) {
                cout << exception.getMessage() << endl;
                cin.clear();
                cin.ignore();
            }
        }

        if(bank.checkAccount(bucket.getSum()) ) {
            if (bucket.getSum() != 0) {
                cout << "Do you want to make a purchase??" << endl;
                if(confirm_choice()) {
                    bank.makeAPurchase(bucket.getSum());
                } 
                
            }
        } 

        bucket.freeBucket();
        cout << "Do you want to continue buying??" << endl;
        if(!(confirm_choice()) ) {
            break;
        }
        
    }

    bank.checkAccount();
    // }}}
    return 0;
}

