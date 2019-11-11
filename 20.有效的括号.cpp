/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int i, n=s.length();
        stack<char> tmp;
        char c;
        for (i=0; i<n; ++i) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{': {
                    tmp.push(s[i]);
                    break;
                }
                case ')': 
                case ']':
                case '}': {
                    if (tmp.empty()) return false;
                    c = tmp.top();
                    tmp.pop();
                    if (s[i]!=c+1 && s[i]!=c+2) return false;
                }
            }
        }
        if (tmp.empty()) return true;
        else return false;
    }
};
// @lc code=end

