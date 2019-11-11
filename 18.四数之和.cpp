/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int i, j, left, right, n=nums.size(), tmp;
        if (n<4) return result;
        sort(nums.begin(), nums.end());
        for (i=0; i<n-3; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if (nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for (j=i+1; j<n-2; ++j) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if (nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                left = j+1; right = n-1;
                while (left < right) {
                    tmp = nums[i] + nums[j] + nums[left] + nums[right];
                    if (tmp==target) {
                        result.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        left++; right--;
                        while (nums[left]==nums[left-1]&&left<right) left++;
                        while (nums[right]==nums[right+1]&&left<right) right--;
                    }
                    else if (tmp<target) left++;
                    else right--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

