#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> ind;
        int i, result=0, col;
        map<int, int> rows, columns;
        map<int, int>::iterator r, c;
        for (i=0; i<indices.size(); ++i) {
            rows[indices[i][0]] += 1;
            columns[indices[i][1]] += 1;
        }
        
        col = n-rows.size();
        
        for (c=columns.begin(); c!=columns.end(); ++c) {
            if ((c->second)%2) result += col;
        }
        
        for (r=rows.begin(); r!=rows.end(); ++r) {
            if ((r->second%2)) result += m;
            for (c=columns.begin(); c!=columns.end(); ++c) {
                if ((c->second%2) && (r->second%2)) result--;
                if (!(c->second%2) && (r->second%2)) result++;
                if ((c->second%2) && !(r->second%2)) result++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << s.minimumSwap(s1, s2) << endl;
    return 0;
}