#include "products.h"

Marker::Marker(int number)
{
    this->number = number;
}

Marker::Marker()
{
    this->number = 0;
}

Marker::~Marker()
{
}

// Ingredients : Ingredients(number)
Ingredients::Ingredients()
{
    consist = "";
}

Ingredients::Ingredients(const char* consist) 
{
    this->consist = consist;
}

Ingredients::Ingredients(const String& consist)
{
    this->consist = consist;
}

String Ingredients::getConsist()
{
    return consist;
}

Ingredients::~Ingredients()
{
}

// Goods

Good::Good()
{
    price = 0;
}

Good::Good(float price)  
{
    this->price = price;
}

float Good::getPrice()
{
    return price;
}

Good::~Good()
{
}

// Product

Product::Product(const char* name, const char* consist, float price, int number) : Marker(number), Good(price), Ingredients(consist)
{
    this->name = name;
}

Product::Product() : Marker(), Good(), Ingredients()
{
    name = "";
}

Product::Product(const Product& obj2) : Marker(obj2.number), Good(obj2.price), Ingredients(obj2.consist)
{
    this->name = obj2.name; 
}

Product::~Product()
{
}

Product Product::operator= (const Product& obj2)
{
    this->name = obj2.name;
    this->price = obj2.price;
    this->consist = obj2.consist;
    this->number = obj2.number;
    
    return *this;
}

int Product::getNumber()
{
    return number;
}

void Product::operator() (const char* name, const char* consist, float price, int number)
{
    this->name = name;
    this->consist = consist;
    this->price = price;
    this->number = number;
}

ostream & operator<<(ostream& out, const Product& obj)
{
    out << "Name:     " << obj.name << endl;
    out << "Consist:  " << obj.consist << endl;
    out << "Price:    " << obj.price << endl;
    out << "Number:   " << obj.number << endl;

    return out;
}

istream& operator>>(istream &in, Product& obj) throw(BadInput, WrongData)
{
    in >> obj.name;
    in >> obj.consist;
    in >> obj.price;
    if(in.fail()) {
        throw BadInput("Wrong price");
    }
    if(obj.price <= 0) {
        throw WrongData("It is wrong price");
    }
    in >> obj.number;
    if(in.fail()) {
        throw BadInput("Wrong number");
    }
    if(obj.number <= 0) {
        throw WrongData("It is wrong number");
    }

    return in;
}

Bucket::Bucket()
{
    this->products = new Node<Product>;
}

Bucket::~Bucket()
{
    delete this->products;
}

void Bucket::freeBucket()
{
    if(!products->isEmptyNode) {
        delete products;
    }
}

void Bucket::addToTheBucket(Product inputObject)
{
    products->add(inputObject, inputObject.getPrice());
}

long Bucket::getSum()
{
    return products->getSumOfTheKeys();
}

// Shop

Shop::Shop()
{
    int i = 0, n;
    Product temp;

    //cout << "Specify the number of products" << endl;
    //n = getNaturalNumber();

    //cout << n << i;
    //while(i < n)
    //{
    //    cout << "Enter product " << i + 1 << " in format:" << endl;
    //    cout << "Name -     " << endl;
    //    cout << "Consist -  " << endl;
    //    cout << "Price -    " << endl;
    //    cout << "Number -   " << endl;
    //    try {
    //        cin >> temp;
    //    }
    //    catch(BadInput exception) {
    //        cout << exception.getMessage() << endl;
    //        cin.clear();
    //        cin.ignore();
    //        continue;
    //    }
    //    catch(WrongData exception) {
    //        cout << exception.getMessage() << endl;
    //        cin.clear();
    //        cin.ignore();
    //        continue;
    //    }   
    //    availability.add(temp, temp.getNumber());
    //    i++;
    //    cout << "Product added" << endl;
    //} 
    
    Product product[6];

    product[0]("Bread", "flour", 5000, 1);
    product[1]("Milk", "milk", 6800, 2); 
    product[2]("Butter", "cream", 16300, 3); 
    product[3]("Cheese", "Milk, salt", 32000, 4); 
    product[4]("Cookies", "flour, chocolate", 12500, 5); 
    product[5]("Candy bar", "chocolate, sugar", 6200, 6);  
    for(i = 0; i < 6; i++) {
        availability.add(product[i], product[i].getNumber());
    }
}

void Shop::showAvailablity()
{
    Node<Product>::Iterator iterator = availability.begin();

    for (; iterator <= availability.end(); ++iterator) {
        cout << "iteration "<< endl;
        cout << *iterator;
    }
    
    cout << "end" << endl; 
    //cout << availability;
}


Product Shop::getProductByNumber(int number)
{
    Node<Product>::Iterator iterator; 

    //for (iterator = availability.begin(); iterator < availability.end(); ++iterator) {
    //}
    
    return availability.findElementWithKey(number);
}

void Bank::setScore(long score)
{
    this->score = score;
}

void Bank::checkAccount()
{
    cout << "Your score is:" << score << endl;
}

int Bank::checkAccount(long bill)
{
    if(bill > score) {
        cout << "You have only:" << score << endl;
        cout << "It's not enough of pay bill in:"<< bill << endl;
        return 1;
    } else {
        cout << "You have score:" << score << endl;
        cout << "It's enough to pay bill in:" << bill << endl;
    }
    
    return 0;
}

int Bank::makeAPurchase(long bill)
{
    if(bill > score) {
        cout << "You have only:" << score << endl;
        cout << "It's not enough of pay bill in:" << bill << endl;
        return 1;
    } else {

        score = score - bill;
        cout << "score - bill = ..... " << endl;
        cout << "Now score =" << score << endl;
    }
    
    return 0;
}

int confirm_choice(void)
{
    char arg;
    cout << "Set (Y/N)" << endl;
    while (1) {
        cin >> arg;
        if (arg == 'Y' || arg == 'y') {
            return 1;
        }
        if (arg == 'N' || arg == 'n') {
            return 0;
        } else {
            cout << "Wrong key" << endl;
        }
    }
}

int Shop::checkKey(int key)
{
    return availability.keyAreExists(key);
}

int getNaturalNumber(bool allowZero)
{
    int number;

    while(true) {


        try {
            cin >> number;
            if(cin.fail()) {
                throw BadInput("The value must be a number");
            } else if (number < 0) {
                throw WrongData("Inputted number is < 0");
            } else if (! allowZero && number == 0) {
                throw WrongData("Inputted number is 0");
            } else {
                break;
            }

        }
        catch(BadInput exception) {
            cout << exception.getMessage() << endl;
            cin.clear();
            cin.ignore();
        }
        catch(WrongData exception) {
            cout << exception.getMessage() << endl;
            cin.clear();
            cin.ignore();
        }
    } 
    
    return number;
}

