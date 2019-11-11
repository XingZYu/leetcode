/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size(), i, j, k, tmp;
        if (n<3) return 0;
        int result = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for (i=0; i<n; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            j=i+1; k=n-1;
            while (j<k) {
                tmp = nums[i] + nums[j] + nums[k];
                cout << tmp << " " ;
                if (tmp==target) return target;
                if (abs(tmp-target)<abs(result-target)) {
                    result = tmp;
                }
                if (tmp<target) j++;
                else k--;
            }
        }
        cout << result << endl;
        return result;
    }
};
// @lc code=end

