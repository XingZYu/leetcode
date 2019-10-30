/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        int i, j;
        vector<int> opt(n+1, 0);
        for (i=0; i<=n; ++i) opt[i] = i-1;
        for (i=0; i<n; ++i) {
            for (j=0; i-j>=0 && s[i-j]==s[i+j] && i+j<n; ++j) {
                opt[i+j+1] = min(opt[i+j+1], opt[i-j]+1);
            }
            for (j=0; i-j>=0 && i+j+1<n && s[i-j]==s[i+j+1]; ++j) {
                opt[i+j+2] = min(opt[i+j+2], opt[i-j]+1);
            }
        }
        return opt[n];
    }
};
// @lc code=end

