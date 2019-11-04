/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        char c;
        string subs;
        int result=0;
        for (int i=0; i<s.length(); ++i) {
            c = s[i];
            if (i<s.length()-1) subs = s.substr(i, 2);
            else subs = c;
            if (subs.compare("CM")==0) result+=900;
            else if (subs.compare("CD")==0) result+=400;
            else if (subs.compare("XC")==0) result+=90;
            else if (subs.compare("XL")==0) result+=40;
            else if (subs.compare("IX")==0) result+=9;
            else if (subs.compare("IV")==0) result+=4;
            else {
                switch (c)
                {
                case 'M':
                    result+=1000;
                    break;
                case 'D':
                    result+=500;
                    break;
                case 'C':
                    result+=100;
                    break;
                case 'L':
                    result+=50;
                    break;
                case 'X':
                    result+=10;
                    break;
                case 'V':
                    result+=5;
                    break;
                case 'I':
                    result+=1;
                    break;
                default:
                    break;
                }
                continue;
            }
            i++;
        }
        return result;
    }
};
// @lc code=end

