class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size(), i, mod;
        int dp[3] = {0, 0, 0};
        int a, b, c;
        for (i=0; i<n; ++i) {
            mod = nums[i] % 3;
            a = dp[(3-mod)%3];
            b = dp[(4-mod)%3];
            c = dp[(5-mod)%3];

            if (a || mod == 0) dp[0] = max(dp[0], a + nums[i]);
            if (b || mod == 1) dp[1] = max(dp[1], b + nums[i]);
            if (c || mod == 2) dp[2] = max(dp[2], c + nums[i]);

        }
        return dp[0];
    }
};