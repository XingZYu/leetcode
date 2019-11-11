#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> neighbors(vector<int> s, int n, int m) {
        vector<vector<int>> neb;
        if (s[0]-1 >= 0) neb.push_back(vector({s[0]-1, s[1]}));
        if (s[1]-1 >= 0) neb.push_back(vector({s[0], s[1]-1}));
        if (s[1]+1 < m) neb.push_back(vector({s[0], s[1]+1})); 
        if (s[0]+1 < n) neb.push_back(vector({s[0]+1, s[1]}));
        return neb;
    }   

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int i, j, edge, x, y, result=0, k;
        queue<vector<int>> succ;
        vector<vector<int>> neighbor;
        vector<vector<int>> visited(n, vector(m, 0));
        vector<int> p, q;

        for (i=1; i<grid.size()-1; ++i) {
            for (j=1; j<grid[0].size()-1; ++j) {
                if (grid[i][j]==0 && visited[i][j]==0) 
                {
                    edge = 1;
                    // cout << i << " " << j << endl;
                    succ.push(vector({i, j}));
                    while (!succ.empty()) {
                        p = succ.front();
                        succ.pop();
                        visited[p[0]][p[1]] = 1;
                        neighbor = neighbors(p, n, m);
                        if (neighbor.empty()) continue;
                        for (k=0; k<neighbor.size(); ++k) {
                            x = neighbor[k][0];
                            y = neighbor[k][1];
                            cout << x << " " << y << endl;
                            if (visited[x][y] == 1 || grid[x][y] == 1) continue;
                            if (grid[x][y] == 0) {
                                if (x==n-1 || x==0 || y==m-1 || y==0) {
                                    edge=0;
                                }
                                succ.push(vector({x, y}));
                            }
                        }
                    }
                    if (edge == 1) result++;
                }
            }
        }
        return result;
        
    }
};

int main() {

}