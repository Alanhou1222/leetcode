class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int front = 0;
        int sum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum >= target){
                while(sum - nums[front] >= target){
                    sum -= nums[front];
                    front ++;
                }
                ans = min(ans, i - front + 1);
            }
        }
        return (ans == INT_MAX) ? 0:ans;
    }
};