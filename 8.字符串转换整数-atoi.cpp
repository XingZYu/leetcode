/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int flag = 0;
        char c, sign='n';
        for (int i=0; i<str.length(); ++i) {
            c = str[i];
            if (c>=48 && c<=57) {
                flag = 1;
                result *= 10;
                result += (int) c-48;
                if (result > INT_MAX && sign!='-') {
                    result = INT_MAX;
                    break;
                }
                if (-result < INT_MIN && sign=='-') {
                    result = INT_MIN;
                    break;
                }
            }
            else {
                if (flag) break;
                else if (c ==' ' && !flag) continue;
                else if ((c=='-' || c=='+') && sign == 'n') {
                    sign = c;
                    flag = 1;
                }
                else return 0;
            }
        }
        // cout << flag << endl;
        if (sign=='-') return -result;
        else return result;
    }
};
// @lc code=end

