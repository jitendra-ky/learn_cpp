#include <iostream>
using namespace std;

int my_sum(int a, int b); // this is a basic sum function

int main() {
    // your code goes here
    int a, b, c;
    cout << "hellow world here I am" << endl;
    cout << "here we go" << endl;

    // now taking the input a, b and c;
    cin >> a;
    cin >> b;
    // cin >> c;

    // find the sum
    int sum_ab = my_sum(a, b);

    // print the answer
    cout << "the sum of " << a << " + " << b << " = " << sum_ab << endl;

    return 0;
}

int my_sum(int a, int b) {
    /*
    this is a basic sum function 
    which take a and b as input and return 
    a + b
    */
    int ans;
    ans = a + b;
    // we get the answer now output it
    return ans;
}