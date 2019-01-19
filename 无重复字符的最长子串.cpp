#include <string>
#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> record;
        int max = 0, i = 0, j = 0;
        int n = s.length();
        while (i<n && j<n)
        {
            if (record.find(s[j]) == record.end())
            {
                record[s[j++]] = 1;
                max = ((j - i) > max) ? (j - i) : max;
            }
            else
            {
                record.erase(s[i++]);
            }
        }
        return max;
    }
};
