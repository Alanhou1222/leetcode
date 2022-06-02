class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int max = 0;
        int secondMax = 0;
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                secondMax = max;
                max = nums[i];
                index = i;
            }
            else if(nums[i] > secondMax){
                secondMax = nums[i];
            }
        }
        if(max >= secondMax*2){
            return index;
        }
        return -1;
    }
};