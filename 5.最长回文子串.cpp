/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome_Original(string s) {
        int n = s.length();
        string result, tmp;
        int i, j;
        for (i=0; i<n && s.length() - i > result.length() / 2; ++i) {
            tmp = s[i];
            for (j=1; i-j>=0 && i+j<n && s[i-j]==s[i+j]; j++) {
                tmp.push_back(s[i+j]);
                tmp.insert(0, 1, s[i-j]);
            }
            if (tmp.length() >= result.length()) result = tmp;
            tmp = "";
            for (j=0; i-j>=0 && i+j+1<n && s[i-j]==s[i+j+1]; j++) {
                tmp.push_back(s[i+j+1]);
                tmp.insert(0, 1, s[i-j]);
            }
            if (tmp.length() >= result.length()) result = tmp;
        }
        return result;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int start=0, max_len=0, i=0, j=0;
        for (i=0; i<n && n-i > max_len / 2; ++i) {
            j=0;
            while (i-j-1>=0 && i+j+1<n && s[i-j-1] == s[i+j+1]) j++;
            if (2*j+1 > max_len) {
                max_len = 2*j+1;
                start = i-j;
            }
            j=0;
            while (i-j>=0 && i+j+1<n && s[i-j] == s[i+j+1]) j++;
            if (2*j > max_len) {
                max_len = 2*j;
                start = i-j+1;
            }
        }
        return s.substr(start, max_len);
    }
};
// @lc code=end

