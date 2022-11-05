class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> dict;
        for(auto num: nums){
            if(dict.find(num) == dict.end() && num != 0)
                dict.insert(num);
        }
        return dict.size();
    }  
};