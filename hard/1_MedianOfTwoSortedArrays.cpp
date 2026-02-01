/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size(); 
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;
        
        int left = 0, right = m; 
        
        while (left <= right) {
            // Разделяем nums1 на две части
            int partition1 = (left + right) / 2;
            int partition2 = half - partition1;
            
            // Получаем элементы вокруг разделения
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            // Проверяем правильность разделения
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Нашли правильное разделение
                if (total % 2 == 1) {
                    // Нечетное количество элементов
                    return max(maxLeft1, maxLeft2);
                } else {
                    // Четное количество элементов
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
            } else if (maxLeft1 > minRight2) {
                // Слишком много элементов из nums1 в левой части
                right = partition1 - 1;
            } else {
                // Слишком мало элементов из nums1 в левой части
                left = partition1 + 1;
            }
        }
        
        return 0.0;
    }
};

int main() {
    Solution temp;
    vector<int> tempVec1{1,5,7}, tempVec2{1,4,7,9,12};

    cout << temp.findMedianSortedArrays(tempVec1, tempVec2) << endl; 

    return 0; 
}