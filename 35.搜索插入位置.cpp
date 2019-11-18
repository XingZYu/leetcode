/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = (left + right) / 2;
        if (nums[mid] < target) return binarySearch(nums, left, mid-1, target);
        if (nums[mid] > target) return binarySearch(nums, mid+1, right, target);
        return mid; 
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), pos, i;
        pos = binarySearch(nums, 0, n-1, target);
        if (pos == -1) {
            for (i=pos; i<n; ++i) {

            }
        }
        else return pos;
    }
};
// @lc code=end

