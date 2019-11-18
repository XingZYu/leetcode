class Solution {
public:
    string findParent(unordered_map<string, string>&parent, string r1, string r2) 
    {
        string a, b;
        if (r1 == r2) return r1;
        if (parent.find(r1) == parent.end()) a = "";
        else a = findParent(parent, parent[r1], r2);
        while (parent.find(r2) != parent.end()) 
        {
            r2 = parent[r2];
            if (r2 == r1) return r1;
        }
        return a;
    }
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        int n = regions.size(), i, j, m;
        for (i=0; i<n; ++i) {
            m = regions[i].size();
            for (j=1; j<m; ++j) {
                parent[regions[i][j]] = regions[i][0]; 
            }
        }
        return findParent(parent, region1, region2);
    }
};