/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

nums contains distinct values sorted in ascending order.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/

/*
Первое решение, подходит для маленьких массивов
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) 
            if (nums[i] >= target) return i;
        
        return nums.size();
    }
};
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (r + l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;
    }
};


int main() {

    Solution temp;
    vector<int> tempVec1{1,3,5,6};
    cout << temp.searchInsert(tempVec1, 4);

    return 0;
}