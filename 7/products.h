#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include <iostream>
#include <cstring>
#include <string>
#include "string.h"
#include "tree.h"
#include "exception.h"
#include <fstream>

const int NUMBER_OF_PRODUCTS = 6;
const int BUFFER_SIZE = 128;

int confirm_choice(void);

int inputNumberInRange(const int, const int);
int getNaturalNumber(bool allowZero = true);

class Marker {
public:
    Marker(int);
    Marker();
    virtual ~Marker();
protected:
    int number;
};

class Ingredients : public virtual Marker {
public:
    Ingredients();
    Ingredients(const char*);
    Ingredients(const string&);
    virtual string getConsist();
    virtual ~Ingredients();
protected:
    string consist;
};

class Good : public virtual Marker {
public:
    Good(float);
    Good();
    virtual ~Good();
    virtual float getPrice();
protected:
    float price;
};

class Product: public virtual Good , public virtual Ingredients {
public:
    Product(const char *, const char*, float, int);
    Product(const Product &);
    Product();
    virtual ~Product();
    virtual int getNumber();
    virtual Product operator= (const Product&);
    virtual void operator() (const char*, const char*, float, int);
    friend ostream & operator<<(ostream &, const Product&);
    friend istream & operator>>(istream &,  Product&) throw(BadInput, WrongData);
    virtual int write(ofstream&);
    virtual int read(ifstream &);
    virtual int binWrite(ofstream&);
    virtual int binRead(ifstream &);
protected:
    string name;
};

class Bucket {
public:
    Bucket();
    ~Bucket();
    void freeBucket();
    long getSum();
    void addToTheBucket(Product);
    int showProducts();
    
    int write(const char*);
    int read(const char*);
    int binWrite(const char*);
    int binRead(const char*);
    int clearFile(const char*);
    
    bool isFree;
private:
    Node<Product>* products;
};

class Shop {
public:
    Shop();
    void showAvailablity();
    int checkKey(int);
    Product getProductByNumber(int);
private:
    Node<Product> availability;
};

class Bank {
public:
    void setScore(long score = 50000);
    void checkAccount();
    int checkAccount(long);
    int makeAPurchase(long);
private:
    long score;
};

#endif
