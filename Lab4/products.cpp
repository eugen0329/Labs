#include "products.hpp"

Ingredient::Ingredient(const char* consist)
{
    this->consist = consist;
}

Ingredient::Ingredient(const string consist)
{
    this->consist = consist;
}

Good::Good(int price)
{
    this->price = price;
}

Milk::Milk(const Milk& obj2) : Good(obj2.price),
Ingredient(obj2.consist)
{
    volume = obj2.volume;
}

Milk::Milk(int price, int volume, const char* consist) : Good(price),
Ingredient(consist)
{
    this->volume = volume;
}

int Good::getPrice()
{
    return price;
}

ostream& operator<<(ostream& out, Milk obj)
{
    out << obj.volume << endl;
    out << obj.price << endl;
    out << obj.consist << endl;
    
    return out;
}
