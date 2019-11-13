/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j, n=haystack.length(), m=needle.length();
        if (m==0) return 0;
        for (i=0; i<n-m+1; ++i) {
            if (haystack[i]==needle[0]) {
                for (j=1; j<m && needle[j]==haystack[i+j]; ++j) ;
                if (j==m) return i;  
            }
        }
        return -1;
    }
};
// @lc code=end

