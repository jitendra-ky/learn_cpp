#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // Include this to use std::max

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stk;
        int mx = 0; // Initialize mx to 0
        int n = s.size();

        // Initialize the stack with a base index of -1
        stk.push(-1);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                stk.push(i); // Push the index of '('
            }
            else
            {
                stk.pop(); // Pop the top element
                if (stk.empty())
                {
                    // If stack is empty, push the current index as a new base
                    stk.push(i);
                }
                else
                {
                    // Calculate the length of the current valid substring
                    mx = max(mx, i - stk.top());
                }
            }
        }

        return mx; // Return the maximum length of valid parentheses
    }
};

int main()
{
    Solution solution;
    string s = "(()())";
    cout << "Longest valid parentheses length: " << solution.longestValidParentheses(s) << endl;
    return 0;
}
