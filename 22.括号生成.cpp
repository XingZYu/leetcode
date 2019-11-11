/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    void add_string(string s, int left, int right) {
        if (left==0 && right==0) {
            result.push_back(s);
            return ;
        }
        if (left>0) add_string(s+"(", left-1, right+1);
        if (right>0) add_string(s+")", left, right-1);
    }
    vector<string> generateParenthesis(int n) {
        add_string("", n, 0);
        return result;
    }
};
// @lc code=end

