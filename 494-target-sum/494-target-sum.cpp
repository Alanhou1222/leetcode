class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num:nums) sum += num;
        int newTarget = sum+target;
        if(sum < abs(target) || newTarget % 2 != 0){
            return 0;
        }
        newTarget /= 2;
        newTarget = abs(newTarget);
        vector<int> dp(newTarget+1,0);
        dp[0] = 1;
        for(int num:nums){
            for(int i = newTarget; i>=0; i--){
                if(i>=num) dp[i] += dp[i-num]; 
            }
        }
        return dp[newTarget];
    }
};