/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        unordered_set<int> set(nums1.begin(), nums1.end());

        for (int i : nums2){
             if (set.erase(i)) result.push_back(i);
        }

        return result;
    }
}; 

int main() {
    Solution temp;
    vector<int> tempVec1{1,5,7}, tempVec2{3,6,7,6,10,2,1},
    tempResVec = temp.intersection(tempVec1, tempVec2); 

    for (int i = 0; i < tempResVec.size(); i++) {
        cout << tempResVec[i] << " "; 
    }

    return 0;
}