#include <iostream>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        int i, n=s.size();
        for (i=0; i<n; ++i) {
            if (s[i]=='(') {
                stk.push(i);
            }
            if (s[i]==')') {
                if (stk.empty()) {
                    s[i] = ' ';
                }
                else stk.pop();
            }
        }
        while (!stk.empty()) {
            i = stk.top();
            stk.pop();
            s[i] = ' ';
        }
        for (i=0; i<n; ++i) {
            if (s[i] == ' ') {
                s.erase(i, 1);
                i--;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    string str;
    cin >> str;
    cout << s.minRemoveToMakeValid(str) << endl;
    return 0;
}