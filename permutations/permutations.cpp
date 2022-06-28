class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans, nums, 0, nums.size()-1);
        return ans;
    }
    
    void solve(vector<vector<int>> &ans, vector<int> &nums, int l, int r){
        if(l == r) ans.push_back(nums);
        else{
            for(int i = l; i <= r; i++){
                swap(nums[l], nums[i]);
                solve(ans, nums, l+1, r);
                swap(nums[l], nums[i]);
            }
        }
    }
};