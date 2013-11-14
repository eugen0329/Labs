#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include <iostream>
#include <cstring>
#include "string.hpp"

typedef int date_t;

class Good {
public:
    Good(int);
    int getPrice();
protected:
    int price;
};

class Ingredient {
public:
    Ingredient(const char*);
    Ingredient(const string);
protected:
    string consist;
};

class Milk : public Good, public Ingredient {
public:
    Milk(int, int, const char*);
    Milk(const Milk&); 
    friend ostream& operator<<(ostream&, Milk);
private:
    int volume;    
};

class Bread : public Good, public Ingredient {
public:

private:
    int weight;    
};


#endif
