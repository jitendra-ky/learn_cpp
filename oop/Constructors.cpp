#include <string>
#include <iostream>

using namespace std;

class Car {
    public:
        string brand;
        string model;
        int year;
        Car(string x, string y, int z) {
            brand = x;
            model = y;
            year = z;
        }
};

int main() {
    Car carobj1("BMW", "X5", 1999);
    Car carobj2("Ford", "Mustange", 1969);

    //printing the values
    cout << carobj1.brand << endl;
    cout << carobj2.brand << endl;

    //now changint the vlaues
    carobj1.brand = "BMW-new";
    carobj2.brand = "Ford-new";

    // printing the new data;
    cout << carobj1.brand << endl;
    cout << carobj2.brand << endl;
}