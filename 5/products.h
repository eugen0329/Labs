#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include <iostream>
#include <cstring>
#include "string.h"
#include "tree.h"
#include "exception.h"

const int NUMBER_OF_PRODUCTS = 6;

int confirm_choice(void);

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
    Ingredients(const String&);
    virtual String getConsist();
    virtual ~Ingredients();
protected:
    String consist;
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
protected:
    String name;
};

class Bucket {
public:
    Bucket();
    ~Bucket();
    void freeBucket();
    long getSum();
    void addToTheBucket(Product);
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
    void setScore(long);
    void checkAccount();
    int checkAccount(long);
    int makeAPurchase(long);
private:
    long score;
};

#endif
