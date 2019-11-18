/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, n=nums.size(), k, v;
        j = n - 1;
        if (n==0 || n==1) return ;
        while (j > 0 && nums[j-1] >= nums[j]) j--;
        if (j == 0) {
            for (i=0; i<n/2; ++i) {
                v = nums[i];
                nums[i] = nums[n-i-1];
                nums[n-i-1] = v;
            }
            return ;
        }
        i = n - 1;
        v = nums[j]; 
        k = j;
        while (i >= j) {
            if (nums[i] > nums[j-1] && nums[i] < v) {
                k = i;
                v = nums[i];
            } 
            i--;
        }
        nums[k] = nums[j-1];
        nums[j-1] = v; 
        sort(nums.begin()+j, nums.end());
    }
};
// @lc code=end

