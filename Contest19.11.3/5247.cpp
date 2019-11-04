#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int i, result=0, j;
        vector<int>tmp1, tmp2;
        for (i=0; i<s1.length(); ++i) {
            if (s1[i]=='x' && s2[i]=='y') tmp1.push_back(i);
            else if(s1[i]=='y' && s2[i]=='x') tmp2.push_back(i);
        }
        int m=tmp1.size(), n=tmp2.size();
        for (i=0; i<m-1; i+=2) result += 1;
        for (j=0; j<n-1; j+=2) result += 1;
        for (;i<m && j<n; i++, j++) result += 2;
        if (i!=m || j!=n) return -1;
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