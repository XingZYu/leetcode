#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), count=0, start=-1, i, j, l, result=0;
        vector<int> odd_count(n+1, 0);
        map<int, int> odd_num;
        for(i=0; i<n; ++i) {
            if (nums[i]%2==1) {
                count++;
                odd_num[count] = i;
            }
        }
        odd_num[0]=-1; odd_num[count+1] = n;
        if (count < k) return 0;
        for (i=1; i<=count-k+1; ++i) {
            for (j=odd_num[i-1]; j<odd_num[i]; ++j) {
                for (l=odd_num[i+k-1]; l<odd_num[i+k]; ++l) result++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int k, tmp;
    while (cin>>tmp) { 
        nums.push_back(tmp); 
    }
    k=nums.back();
    nums.pop_back();
    cout << s.numberOfSubarrays(nums, k) << endl;
    return 0;
}