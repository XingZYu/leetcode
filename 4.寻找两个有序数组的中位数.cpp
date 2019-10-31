/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution {
public:
    int search(int low, int high, int sum, vector<int>& a, vector<int>& b) {
        int middle = (low + high) / 2;
        if (middle > 0 && b[middle-1] > a[sum-middle]) {
            return search(low, middle, sum, a, b);
        }
        if (middle < b.size() && b[middle] < a[sum-middle-1]) {
            return search(middle+1, high, sum, a, b);
        }
        return middle;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        if (m < n) return this->findMedianSortedArrays(nums2, nums1);
        int flag;
        flag = (m+n)%2;

        int i, left, right;

        if (n==0) {
            left = nums1[(m+1)/2-1];
            if (!flag)
            right = nums1[(m+1)/2];
        }

        if (n!=0) {
            i=search(0, n, (m+n+1)/2, nums1, nums2);
            if (i==0) {
                left = nums1[(m+n+1)/2-i-1];
                if ((m+n+1)/2-i == m) right = nums2[i];
                else right = min(nums1[(m+n+1)/2-i], nums2[i]);
            } 
            else if (i==n) {
                if ((m+n+1)/2-i == 0) left = nums2[i-1];
                else left = max(nums1[(m+n+1)/2-i-1], nums2[i-1]);
                right = nums1[(m+n+1)/2-i];
            } 
            else {
                left = max(nums1[(m+n+1)/2-i-1], nums2[i-1]);
                right = min(nums1[(m+n+1)/2-i], nums2[i]);
            }
        }

        if (flag) return (double) left;
        if (!flag) return (double) (left + right) / 2.0; 
        return 0.0;
    }
};
// @lc code=end

