#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        unordered_map<int, int> map;
        for (int i=0; i<nums.size(); ++i){
            int diff = target-nums[i];
            if (map.find(diff)!=map.end())
            {
                result[1]=map[diff]; result[0]=i;
                return result;
            }
            map[nums[i]]= i;
        }
        return result;
    }
};
