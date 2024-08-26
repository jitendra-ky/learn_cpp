#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    cout << string("abc").find("q") << endl;

    cout << (string("abc").find("a") != string::npos) << endl;

    list<int> lc = {1,2,3};
    cout << (lc.empty()) << endl;

    if (lc.empty()) {
        cout << "condition true when lc is empty" << endl;
    }

    return 1;
}