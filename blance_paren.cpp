# include <iostream>
# include <string>
# include <list>
using namespace std;

class Solution
{
public:
    bool isValid(string s) {
        list<char> stk; //define our stack which is a list of charater 
        // and the function that I use stk list methods that I will use are
        // stk.push_back(char)
        // stk.pop_back()
        // stk.empty()
        bool is_balance = true;
        int index = 0;
        while (index < s.size() && is_balance) {
            char paren = s[index];
            if ( string("([{").find(paren) != string::npos ) {
                stk.push_back(paren);
            } else if (stk.empty()) {
                is_balance = false;
            } else {
                const char top = stk.back();
                stk.pop_back();
                if (!isSame(top, paren)) {
                    is_balance = false;
                }
            }
            ++index;
        }
        if (stk.empty()) {
            return true;
        } else {
            return false;
        }
    }

private:
    bool isSame(char p1, char p2)
    {
        if (p1 == '(' && p2 == ')') {
            return true;
        } else if (p1 == '[' && p2 == ']') {
            return true;
        } else if (p1 == '{' && p2 == '}') {
            return true;
        } else {
            return false;
        }
    }
};


int main() {
    Solution sol;
    cout << sol.isValid("()") << endl;
}