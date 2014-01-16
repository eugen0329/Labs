#include "products.h"

int Bucket::write(const char* filename)
{

    if(!products) {
        cout << "The bucket is empty" << endl;
        return 1;
    }

    ofstream out(filename);
    if(!out.is_open()) {
        cout << "error while opening file" << filename << endl;
        exit(1);
    }

    
    out << products->size() << endl;

    Product temp;
    for (Node<Product>::Iterator it = products->begin(); it<= products->end(); ++it) {
        temp = *it;
        temp.write(out);
    }

    
    cout << "Successfully writed" << endl;
    out.close(); 
    return 0;
}

int Product::write(ofstream& out)
{
    out << name << endl;
    out << consist << endl;
    out << price << endl;
    out << number << endl;

    return 0;
}

int Bucket::read(const char* filename)
{
    ifstream in(filename);
    if(!in.is_open()) {
        cout << "error while opening file" << filename << endl;
        exit(1);
    } 
    if(in.eof()) {
        cout << "file is empty" << endl;
    }
    
    std::string buff;
    getline(in, buff);
    int nObjects = strtol(buff.c_str(), NULL, 10);
    if(!nObjects) {
        cout << "file is empty" << endl;
        return 1;
    }

    Product temp;
    for(int i = 0; i < nObjects; i++) {
        temp.read(in);
        this->addToTheBucket(temp);
    }

    in.close();
    return 0;
}

int Product::read(ifstream& in)
{
    std::string buff;

    getline(in, buff);
    name = buff;

    getline(in, buff);
    consist = buff;

    getline(in, buff);
    price = strtol(buff.c_str(), NULL, 10);

    getline(in, buff);
    number = strtol(buff.c_str(), NULL, 10);

    return 0;
}

int Bucket::binWrite(const char* filename)
{
    if(!products) {
        cout << "The bucket is empty" << endl;
        return 1;
    }

    ofstream out(filename, ios::out | ios::binary);
    if(!out.is_open()) {
        cout << "error while opening file" << filename << endl;
        exit(1);
    }

    int size = products->size();

    out.write((char *) &size, sizeof size);

    Product temp;
    for (Node<Product>::Iterator it = products->begin(); it<= products->end(); ++it) {
        temp = *it;
        temp.binWrite(out);
    }

    cout << "Successfully writed" << endl;
    out.close(); 
    return 0;
}

int Product::binWrite(ofstream& out)
{
    int len1 = name.length(); 
    out.write((char*) &len1, sizeof(len1));
    out.write(name.c_str(), len1 * sizeof(char));

    int len2 = consist.length();
    out.write((char*) &len2, sizeof(len2));
    out.write(consist.c_str(), len2 * sizeof(char));

    out.write((char*) &price, sizeof(price));
    out.write((char*) &number, sizeof(number));

    return 0;
}




int Bucket::binRead(const char* filename)
{
    ifstream in(filename, ios::in | ios::binary);
    if(!in.is_open()) {
        cout << "error while opening file" << filename << endl;
        exit(1);
    } 
    in.seekg(0);
    if(in.eof()) {
        cout << "file is empty" << endl;
    }
    
    int nObjects = 0;
    in.read((char*) &nObjects, sizeof(int));

    if(!nObjects) {
        cout << "file is empty" << endl;
        return 1;
    }

    Product temp;
    for(int i = 0; i < nObjects; i++) {
        temp.binRead(in);
        this->addToTheBucket(temp);
    }

    in.close();
    return 0;
}

int Product::binRead(ifstream& in)
{
    int length;
    char buff [STRING_SIZE];

    in.read((char*) &length, sizeof(int));
    in.read(buff, length * sizeof(char));
    name = buff;
   
    in.read((char*) &length, sizeof(length));
    in.read(buff, length * sizeof(char));

    consist = buff;

    in.read((char*) &price, sizeof(price));
    in.read((char*) &number, sizeof(number));

    return 0;
}


int Bucket::clearFile(const char* filename)
{
    ofstream cf(filename, ios::out | ios::trunc);
    if(!cf.is_open()) {
        cout << "error" << endl;
    } else {
        cout << "successfully cleared" << endl;
    }
    cf.close();
    return 0;
}

