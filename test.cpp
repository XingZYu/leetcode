#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool ** opt;
        opt = new bool*[s.length()+1];
        int i, j, k, l;
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
                    if ((s[i] == p[j] || p[j] == '.')) opt[i+1][j+1] = 1;
                    else if (p[j] == '*') {
                        k=0;
                        opt[i][j+2] = 1;
                        while (i+k<s.length() && (s[i+k]==p[j-1] || p[j-1]=='.')) 
                        {
                            opt[i+k+1][j+1]=1;
                            k++;
                        }
                    }
                }
                else {
                    if (p[j]=='*') {
                        if (p[j-1]=='.') {
                            for (k=0; k<=s.length(); ++k) {
                                if (opt[k][j-1]==1) {
                                    for (l=k; l<=s.length(); ++l) opt[l][j+1] = 1;
                                    break;
                                }
                            } 
                        }
                        for (k=0; k<=s.length(); ++k) {
                            if (opt[k][j-1]==1 || opt[k][j]==1) opt[k][j+1] = 1;
                        }
                    }
                }
            }
        }
        return opt[s.length()][p.length()];
    }
};

int main() {
    string s;
    s.push_back('a');
    cout << s.length() << endl;
    s.erase(0,1);
    cout << s.length() << endl;
    return 0;
}