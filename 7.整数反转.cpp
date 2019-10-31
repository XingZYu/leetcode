/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        int tmp = x, n;
        while (tmp != 0) {
            result *= 10;
            result += tmp % 10;
            tmp /= 10;
        }
        if (result > INT_MAX || result < INT_MIN) return 0;
        return result;
    }
};
// @lc code=end

