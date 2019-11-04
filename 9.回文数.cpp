/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int tmp=x, num;
        long tmp_reverse=0;
        while (tmp>0) {
            num = tmp % 10;
            tmp_reverse *= 10;
            tmp_reverse += num;
            tmp /= 10;
        }
        if (x == tmp_reverse) return true;
        else return false;
    }
};
// @lc code=end

