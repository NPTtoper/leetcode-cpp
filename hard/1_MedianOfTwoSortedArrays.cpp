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

/*
Первая попытка P.s. Я - балда, поменыял код, а в ком. вставил новый. В первый раз пытался решить
двумя указателями с начал массивов
class Solution  {
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
}; */

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;
        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high) >> 1; 
            int mid2 = left - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }
        
        return 0; 
    }
};

int main() {
    Solution temp;
    vector<int> tempVec1{1,5,7}, tempVec2{4,7,9,12};

    cout << temp.findMedianSortedArrays(tempVec1, tempVec2) << endl; 

    return 0; 
}