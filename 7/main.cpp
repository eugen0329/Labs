#include <cstdlib>
#include <iostream>
#include "products.h"
#include "tree.h"

using namespace std;

int addGoodsToTheBucket(Shop&, Bucket&);
int makeAPurchase(Bank&, Bucket&);


int main()
{
    // {{{
    int number;
    Shop walmart;
    Bucket bucket;
    Bank bank;

    cout << "  " << sizeof( string) << endl;
    //cout << "Set the bank score" << endl;
    //bank.setScore(getNaturalNumber());
    bank.setScore();

    
    while(true) {
        bank.checkAccount();
        cout << "The availablity of the shop" << endl << endl;
        walmart.showAvailablity();
        
        cout << "Set key " << endl ;
        cout << "1) to set products from keyboard" << endl;
        cout << "2) to load from text file" << endl;
        cout << "3) to load from bin file" << endl;
        cout << "4) to exit without bying or saving" << endl;   
        cout << "5) to free bucket" << endl; 
	cout << "6) to clear some file" << endl;  

        number = inputNumberInRange(1,6);
        if (number == 1) {
            addGoodsToTheBucket(walmart, bucket);
        } else if (number == 2) {
            bucket.read("txtfilename");
        } else if (number == 3) {
            bucket.binRead("binfilename");
        } else if (number == 4) {
            break;
	} else if (number == 5) {
            bucket.freeBucket();
            continue;
        } else if (number == 6) {
            cout << "specify file to clear" << endl;
            cout << "1) to clear txt" << endl;
            cout << "2) to to clear binary" << endl;
            number = inputNumberInRange(1,2);
            if (number == 1) {
                bucket.clearFile("txtfilename");
            } else if (number == 2) {
                bucket.clearFile("binfilename");
            }
            continue;
        }

        system("clear");
        cout  << "You have purchased" <<endl << endl;
        bucket.showProducts();
        cout << "Set key " << endl ;
        cout << "1) to make a purchase" << endl;
        cout << "2) to save in text file" << endl;
        cout << "3) to save in bin file" << endl;
        cout << "4) continue" << endl;   
        cout << "5) to exit without bying or saving" << endl;   

        number = inputNumberInRange(1,5);
        if (number == 1) {
            makeAPurchase(bank, bucket);
            bucket.freeBucket();
        } else if (number == 2) {
            bucket.write("txtfilename");
        } else if (number == 3) {
            bucket.binWrite("binfilename");
        } else if (number == 4) {
            continue;
        } else if (number == 5) {
            break;
        }
        

        cout << "Do you want to continue buying??" << endl;
        if(!(confirm_choice()) ) {
            break;
        }
    }

    bank.checkAccount();
    // }}}
    return 0;
}

int addGoodsToTheBucket(Shop& shop, Bucket& bucket)
{
    int number;

    while(true) {
        cout << "Set the number of the product you want to buy(0 to exit)" << endl;
        number = getNaturalNumber();
        if(number == 0) {
            return 0;
        }
        try {
            bucket.addToTheBucket(shop.getProductByNumber(number));
            cout << "adding..." << endl;
        }
        catch(WrongData exception) {
            cout << exception.getMessage() << endl;
            cin.clear();
            cin.ignore();
        }
    }

    return 0;
}

int makeAPurchase(Bank& bank, Bucket& bucket)
{
    if(bank.checkAccount(bucket.getSum()) ) {
        if (bucket.getSum() != 0) {
            cout << "Do you want to make a purchase??" << endl;
            if(confirm_choice()) {
                bank.makeAPurchase(bucket.getSum());
            } 
            
        }
    } 

    return 0;

