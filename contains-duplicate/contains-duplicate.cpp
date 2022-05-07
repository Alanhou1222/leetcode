class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> count;
        for(int i = 0;i<nums.size();i++){
            if(count.find(nums[i])!=count.end())
                return true;
            count.insert(nums[i]);
        }
        return false;
    }
};