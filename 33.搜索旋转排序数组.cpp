/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int findr(vector<int>& nums, int left, int right) {
        int mid = (left + right) / 2;
        if (nums[left] > nums[right]) {
            if (right == left + 1) return right;
            else return max(findr(nums, left, mid), findr(nums, mid, right));
        }
        else return 0;
    }

    int binarysearch(vector<int>& nums, int left, int right, int target, int n) {
        int mid = (left + right) / 2;
        if (left > right) return -1;
        if (nums[mid % n] == target) return mid;
        if (nums[mid % n] < target) return binarysearch(nums, mid+1, right, target, n);
        if (nums[mid % n] > target) return binarysearch(nums, left, mid-1, target, n);
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size(), r, result;
        if (n == 0) return -1;
        r = findr(nums, 0, n-1);
        result = binarysearch(nums, r, r+n-1, target, n);
        if (result >= n) return result % n;
        return result;
    }
};
// @lc code=end

