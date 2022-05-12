class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int num:nums){
            mp[num]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(pair<int, int> numPair:mp){
            buckets[numPair.second].push_back(numPair.first);
        }
        for(int i = nums.size(); k; i--){
            while(!buckets[i].empty()){
                cout<<buckets[i].back();
                ans.push_back(buckets[i].back());
                buckets[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};