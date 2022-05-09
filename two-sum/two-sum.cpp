class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> numList;
        int index = 0;
        for(int num:nums){
            if(numList[target-num]>0){
                return {numList[target-num]-1,index};
            }
            numList[num] = index+1;
            index++;
        }
        return {0,0};
    }
};