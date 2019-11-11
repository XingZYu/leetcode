/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string tmp;
        vector<string> result;
        int i, j, k, num;
        char c=97;
        if (digits.length()==0) return result;
        for (i=0; i<digits.length(); ++i) {
            num = digits[i]-48;
            if (num<2) continue;
            c=97+(num-2)*3;
            if (num>7) c+=1;
            tmp.push_back(c);
        }
        result.push_back(tmp);
        for (i=0; i<digits.length(); ++i) {
            k = result.size();
            for (j=0; j<k; ++j) {
                string s=result[j];
                num = s[i];
                s[i]++;
                result.push_back(s);
                s[i]++;
                result.push_back(s);
                if (num==112 || num==119) {
                    s[i]++;
                    result.push_back(s);
                }
            }
        }
        return result;
    }
};
// @lc code=end

