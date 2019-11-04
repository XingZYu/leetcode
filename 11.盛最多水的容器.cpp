/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int a=height[0], b=height.back(), result=0;
        int i=0, j=height.size()-1;
        while (i != j) {
            a = height[i];
            b = height[j];
            result = max(result, min(a, b)*(j-i));
            if (height[j] > height[i]) i++;
            else j--;
        }
        return result;
    }
};

// int main() {
//     Solution s;
//     vector<int> nums;
//     int k, tmp;
//     while (cin>>tmp) { 
//         nums.push_back(tmp); 
//     }
//     cout << s.maxArea(nums) << endl;
//     return 0;
// }
// @lc code=end

