/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int i, j, n=strs.size();
        char c;

        if (n==0) return result;

        for (j=0; j<strs[0].length(); ++j) {
            c=strs[0][j];
            for (i=1; i<n && strs[i][j]==c && j<strs[i].length(); ++i);
            if (i!=n) break;
            result.push_back(c);
        }

        return result;
    }
};
// @lc code=end

