/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, n=nums.size(), j;
        if (n==0) return 0;
        for (i=1, j=1; i<n; ++i) {
            if (nums[i] == nums[i-1]) continue;
            else {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
// @lc code=end

