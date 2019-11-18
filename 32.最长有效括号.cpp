/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> par;
        vector<int> sep(1, -1);
        int i, n=s.length(), max_len = 0;
        if (n == 0) return 0;
        for (i=0; i<n; ++i) {
            if (s[i] == '(') {
                par.push(i);
            }
            else {
                if (!par.empty()) par.pop();
                else sep.push_back(i);
            }
        }
        while (!par.empty()) {
            sep.push_back(par.top());
            par.pop();
        }
        sort(sep.begin(), sep.end());
        sep.push_back(n);
        for (i=0; i<sep.size()-1; ++i) {
            if (sep[i+1] - sep[i] - 1 > max_len) max_len = sep[i+1] - sep[i] - 1;
        }
        return max_len;
    }
};
// @lc code=end

