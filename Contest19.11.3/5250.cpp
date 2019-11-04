#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if (nums.size()==1 && nums[0]==1) return true;
        else if (nums.size()==1) return false;
        int a, b, r;
        vector<int>::iterator i;
        for (i=nums.begin(); i<nums.end()-1; ++i) {
            a=min(*i, *(i+1));
            b=max(*i, *(i+1));
            r=min(b%a, a-b%a);
            if (r==1) return true;
            if (r==0) {
                *(i+1) = a;
            }
            else {
                *i = r; 
                *(i+1) = a;
                i--;
            }
        }
        if (*i==1) return true;
        else return false;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int a;
    while (cin >> a) nums.push_back(a);

    cout << s.isGoodArray(nums) << endl;
    return 0;
}