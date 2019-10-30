/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i=0; i<input.length(); ++i) {
            vector<int> left, right;
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                left = diffWaysToCompute(input.substr(0, i));
                right = diffWaysToCompute(input.substr(i+1));
            }
            for (int j=0; j<left.size(); ++j) {
                for (int k=0; k<right.size(); ++k) {
                    if (input[i] == '+') result.push_back(left[j] + right[k]);
                    else if (input[i] == '-') result.push_back(left[j] - right[k]);
                    else result.push_back(left[j] * right[k]);
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(input));
            return result;
        }
        return result;
    }
};
// @lc code=end

