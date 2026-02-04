/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

/*
Attempt 1 (best attempt)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        } else {
            int strLenCumPref = 0, minLenStr = 0;

            for (auto& str : strs)
                minLenStr = min(minLenStr, (int)str.size());

            for (strLenCumPref = 0; strLenCumPref < minLenStr; strLenCumPref++) 
                for (int i = 1; i < strs.size(); i++)
                    if (strs[0][strLenCumPref] != strs[i][strLenCumPref])
                        return strs[0].substr(0, strLenCumPref);
            
            return strs[0];
        }
    }   
};
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution { //Кака, но просто попытка использовать бинарный поиск
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        int minLen = INT_MAX;
        for (auto& s : strs) {
            minLen = min(minLen, (int)s.size());
        }
        
        int low = 1, high = minLen;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return strs[0].substr(0, (low + high) / 2);
    }
    
private:
    bool isCommonPrefix(const vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);

        for (int i = 1; i < strs.size(); i++) 
            if (strs[i].substr(0, len) != prefix) return false;
            
        return true;
    }
};

int main() {

    Solution temp;
    vector<string> words = {"temp", "teper", "teh"};
    cout << temp.longestCommonPrefix(words);

    return 0;
}