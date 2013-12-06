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

//Product Product::operator+ (const Product& obj2)
//{
//    Product temp;
//    temp.volume = obj2.volume;
//    temp.price = obj2.price;
//    temp.producer = obj2.producer;
//    
//    return temp;
//}

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

istream& operator>>(istream &in, Product& obj)
{
    in >> obj.name;
    in >> obj.consist;
    in >> obj.price;
    in >> obj.number;

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
    int i, n;
    Product pr;
    cout << "Enter the number of products in the store" << endl;
    cin >> n;

    Product *product;
    product = new Product [n];

    for(i = 0; i < n; i++)
    {
        cout << "Enter products in format:" << endl;
        cout << "Name -     " << endl;
        cout << "Consist -  " << endl;
        cout << "Price -    " << endl;
        cout << "Number -   " << endl;

        cin >> pr;
        product[i] = pr;
    }
    //cin >> pr;

    //product[0]("Bread", "flour", 5000, 1);
    //product[1]("Milk", "milk", 6800, 2); 
    //product[2]("Butter", "cream", 16300, 3); 
    //product[3]("Cheese", "Milk, salt", 32000, 4); 
    //product[4]("Cookies", "flour, chocolate", 12500, 5); 
    //product[5]("Candy bar", "chocolate, sugar", 6200, 6); 


    for(i = 0; i < n; i++) {
        availability.add(product[i], product[i].getNumber());
    }

    delete[] product;
}

void Shop::showAvailablity()
{
    cout << availability;
}


Product Shop::getProductByNumber(int number)
{
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
