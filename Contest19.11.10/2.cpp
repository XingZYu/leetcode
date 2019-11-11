class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size(), i;
        vector<int> up(0, n), low(0, n);
        vector<vector<int>> result;
        for (i=0; i<n; ++i) {
            if (colsum[i]==2) {
                up[i]++;
                low[i]++;
                upper--;
                lower--;
            }
        }
        for (i=0; i<n; ++i) {
            if (colsum[i]==1) {
                if (upper > 0) {
                    up[i]++;
                    upper--;
                }
                else if (lower > 0) {
                    low[i]++;
                    lower--;
                }
                else return result;
            }
        }
        result.push_back(up);
        result.push_back(low);
        return result;
    }
};