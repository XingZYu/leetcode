/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int i;
        bool flag;
        long x=dividend, y=divisor, a, result=0;
        if ((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0))
        {
            flag = true;
        }
        else flag = false;
        x = abs(x);
        y = abs(y);
        if (dividend==INT_MIN && divisor==-1) return INT_MAX;
        if (x < y) return 0;
        if (dividend == divisor) return 1;
        if (dividend == -divisor) return -1; 
        while (x >= y) {
            i = 0;
            a = y;
            while (x >= a << 1) {
                a = a << 1;
                i++;
            }
            if (flag) result += 1 << i;
            else result -= 1 << i;
            x -= a;
        }
        return result;
    }
};
// @lc code=end

