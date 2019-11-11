/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int i;
        map<int, int> count;
        map<int, int>::iterator itr1, itr2, itr3;
        vector<int> tmp(3, 0);
        if (nums.size()<3) return result;
        for (i=0; i<nums.size(); ++i) {
            count[nums[i]]++;
        }
        for (itr1=count.begin(); itr1!=count.end(); ++itr1) {
            for (itr2=itr1; itr2!=count.end(); ++itr2) {
                itr3 = count.find(-itr1->first-itr2->first);
                if (itr3==count.end() || itr3->first < itr2->first) continue;
                else {
                    if (itr2==itr1 && itr2==itr3 && itr1->second < 3) continue;
                    if (itr2==itr1 && itr1->second < 2) continue;
                    if (itr3==itr2 && itr2->second < 2) continue; 
                    tmp[0] = itr1->first;
                    tmp[1] = itr2->first;
                    tmp[2] = itr3->first;
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
};
// @lc code=end

