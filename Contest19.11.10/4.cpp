class Solution {
public:
    int maxScore(vector<string> &words, map<char, int> &letters, vector<int>& score, int low)
    {
        int result=0, subscore;
        int i, n=words.size(), j, l;
        map<char, int> newletters;
        if (i==n) return 0;
        for (i=low; i<n; ++i) {
            subscore = 0;
            l = (words[i]).length();
            newletters=letters;
            for (j=0; j<l; ++j) {
                if (newletters[words[i][j]] != 0) {
                    newletters[words[i][j]]--;
                    subscore += score[words[i][j]-'a'];
                }
                else break;
            }
            if (j==l) {
                result = max(result, subscore+maxScore(words, newletters, score, i+1));
            }
        }
        return result;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char, int> letter_map;
        vector<char>::iterator itr;
        for (itr=letters.begin(); itr!=letters.end(); ++itr) {
            letter_map[*itr] += 1;
        }
        return maxScore(words, letter_map, score, 0);
    }
};