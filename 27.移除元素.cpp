/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement1(vector<int>& nums, int val) {
        int i, j, n=nums.size();
        if (n==0) return 0;
        for (i=0, j=0; i<n; ++i) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};
// @lc code=end

