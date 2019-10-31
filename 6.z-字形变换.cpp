/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int i, j, next, l;
        if (numRows == 1) return s;
        vector<int> d;
        string result;
        d.push_back(2*numRows-2); 
        d.push_back(0);
        l = s.length();
        for (i=0; i<numRows; ++i) {
            result.push_back(s[i]);
            j = 0;
            next = i + d[0];
            while (next < l) {
                if (d[j] != 0) result.push_back(s[next]);
                j = (j+1) % 2;
                if (d[j] == 0) j = (j+1) % 2;
                next += d[j];
            }
            d[0] -= 2; 
            d[1] += 2;
        }
        return result;
    }
};
// @lc code=end

