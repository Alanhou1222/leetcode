class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int i = 0;
        if(k == 0) return false;
        for(int num:nums){
            int index = num/((long)t+1);
            if(num < 0) index--;
            if(mp.find(index) != mp.end()) return true;
            mp[index] = num;
            if(mp.find(index-1) != mp.end() && (long) num - mp[index-1] <= t) return true;
            if(mp.find(index+1) != mp.end() && (long) mp[index+1] - num <= t) return true;
            if(i >= k){
                int keyToRemove = nums[i-k]/((long)t+1);
                if(nums[i-k] < 0) keyToRemove--;
                mp.erase(keyToRemove);
            }
            
            i++;
        }
        return false;
    }
};