/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int result = 0;
        if (prices.size() < 2) return result;
        while(i < prices.size()-1) {
            if (prices[i+1] > prices[i]) result += prices[i+1] - prices[i];
            i++;
        }
        return result;
    }
};
// @lc code=end

