class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> intersection;
        vector<int> ans;
        for(int num:nums1){
            intersection[num]++;
        }
        for(int num:nums2){
            if(intersection[num] > 0){
                ans.push_back(num);
                intersection[num]--;
            }
        }
        return ans;
     }
};