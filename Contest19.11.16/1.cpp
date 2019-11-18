#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string encode(int num) {
        int t, v=1;
        string result;
        if (num == 0) return 0;
        while (num >= v) {
            num -= v;
            v = v << 1;
        }
        while (v > 0) {
            t = num / v;
            if (t > 0) {
                result += "1";
                num = num % v;
            }
            else result += "0";
        }
        return result;
    }
};

int main() {
    int a = 1 >> 1 ;
    cout << a << endl;
    return 0;
}