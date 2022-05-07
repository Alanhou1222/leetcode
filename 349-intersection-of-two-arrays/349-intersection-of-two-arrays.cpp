class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> appeared;
        vector<int> ans;
        for(int num:nums1){
            appeared[num] = 1;
        }
        for(int num:nums2){
            if(appeared[num]==1){
                ans.push_back(num);
                appeared[num]++;
            }
        }
        return ans;
    }
};