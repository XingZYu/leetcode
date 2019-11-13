/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int m = s.length(), n = words.size();
        if (n == 0) return result;
        int i, j, l = words[0].size();
        unordered_map<string, int> wordmap;
        for (i=0; i<n; ++i) wordmap[words[i]]++;
        for (i=0; i<m-l*n+1; ++i) {
            unordered_map<string, int> visited;
            for (j=0; j<n; ++j) {
                string word = s.substr(i+j*l, l);
                if (wordmap.find(word) != wordmap.end()) 
                {
                    visited[word]++;
                    if (visited[word] > wordmap[word]) break;
                }
                else break;
            }
            if (j == n) result.push_back(i);
        }
        return result;
    }
};
// @lc code=end

