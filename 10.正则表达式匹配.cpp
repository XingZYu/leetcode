/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start

const int N = 1100;
class Solution {
public:
    bool isMatch(const char *s, const char *p)
    {
        bool f[N][N];
        int n = strlen(s), m = strlen(p);
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j) if (f[i][j])
            {
                if (p[j + 1] == '*')
                {
                    if (s[i] == p[j] || p[j] == '.')
                        f[i + 1][j] = 1;
                    f[i][j + 2] = 1;
                }
                else 
                {
                    if (s[i] == p[j] || p[j] == '.') f[i + 1][j + 1] = 1;
                }
            }
        for (int j = 0; j < m; ++ j) if (f[n][j])
            if (p[j + 1] == '*')
                f[n][j + 2] = 1;
        return f[n][m];
    }
    bool isMatch(string s, string p) {
        bool ** opt;
        opt = new bool*[s.length()+1];
        int i, j, k;
        for (i=0; i<=s.length(); ++i) opt[i] = new bool[p.length()+1];
        for (i=0; i<=s.length(); ++i) {
            for (j=0; j<=p.length(); ++j) opt[i][j] = 0;
        }
        opt[0][0] = 1;
        if (s.length() == 0) {
            for (j=0; j<p.length(); ++j) {
                if (p[j]=='*' && (opt[0][j-1]==1 || opt[0][j]==1)) opt[0][j+1] = 1;
            } 
        }

        for (i=0; i<s.length(); ++i) {
            for (j=0; j<p.length(); ++j) {
                if (opt[i][j] == 1) {
                    if (s[i] == p[j] || p[j] == '.') opt[i+1][j+1] = 1;
                    else if (p[j] == '*') {
                        k=0;
                        opt[i][j+1] = 1;
                        while (i+k<s.length() && (s[i+k]==p[j-1] || p[j-1]=='.')) 
                        {
                            opt[i+k+1][j+1]=1;
                            k++;
                        }
                    }
                }
                else {
                    if (p[j]=='*') {
                        for (k=0; k<=s.length(); ++k) {
                            if (opt[k][j-1]==1 || opt[k][j]==1) opt[k][j+1] = 1;
                        }
                    }
                }
            }
        }

        for (j=0; j<p.length(); ++j) {
            if (opt[s.length()][j]) {
                if (p[j+1]=='*') opt[s.length()][j+2] = 1;
            }
        }
        for (i=0; i<s.length(); ++i) {
            for (j=0; j<p.length(); ++j) {
                cout << opt[i][j] << " ";
            }
            cout << endl;
        }
        return opt[s.length()][p.length()];
    }
};
// @lc code=end

