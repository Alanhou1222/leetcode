class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]==0&&end==i){
               return false; 
            }
            end = max(end,i+nums[i]);
        }
        return true;
    }
};