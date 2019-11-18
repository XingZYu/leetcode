class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int i, j, n = grid.size(), m = grid[0].size(), l;
        vector<vector<int>> result;
        result = grid;
        if (k == 0) return result;
        for (l=0; l<k; ++l) {
            for (j=0; j<m; ++j) {
                for (i=0; i<n; ++i) {
                    if (j == m-1) {
                        if (i == n-1) result[0][0] = grid[i][j];
                        else result[i+1][0] = grid[i][j];
                    }
                    else result[i][(j+1)%m] = grid[i][j];
                }
            }
            grid = result;
        }
        return result;
    }
};