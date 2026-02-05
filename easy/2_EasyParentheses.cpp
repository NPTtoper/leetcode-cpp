/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Example 5:
Input: s = "([)]"
Output: false
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> pr;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                pr.push_back(ch);
            } else {
                if (pr.empty()) return false;
                
                char top = pr.back();
                if (ch == ')' && top != '(' ||
                    ch == ']' && top != '[' ||
                    ch == '}' && top != '{') return false;
                pr.pop_back();
            }
        }
        return pr.empty();
    }
};

int main() {

    Solution temp;
    cout << temp.isValid("([)]");

    return 0;
}