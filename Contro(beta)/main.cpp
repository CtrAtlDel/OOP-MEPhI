#include <iostream>

using namespace std;

class base {
public:
    int i;
};

class derived1 : virtual public base {
public:
    int j;
};

class derived2 : virtual public base {
public:
    int k;
};

class derived3 : public derived1, public derived2{
public:
    int sum;

};

int main() {
    derived2 obj;
    obj.k =5;
    return 0;
}
