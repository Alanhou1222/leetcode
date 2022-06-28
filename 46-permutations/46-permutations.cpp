class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> set;
        vector<int> empty;
        solve(ans, set, nums, empty);
        return ans;
    }
    
    void solve(vector<vector<int>> &ans, unordered_set<int> &set, vector<int> &nums, vector<int> &cur){
        for(int num: nums){
            if(set.find(num) == set.end()){
                set.insert(num);
                cur.push_back(move(num));
                if(cur.size() == nums.size()){
                    ans.push_back(cur);
                }
                else{
                    solve(ans,set,nums,cur);
                }
                set.erase(num);
                cur.pop_back();
            }
        }
    }
};