class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        mergeSort(nums,l,l+(r-l)/2);
        mergeSort(nums,l+(r-l)/2+1,r);
        merge(nums,l,r);
    }
    void merge(vector<int>& nums, int l, int r){
        vector<int> temp;
        int m = l+(r-l)/2;
        int l1 = l;
        int l2 = m+1;
        while(l1 <= m && l2 <= r){
            if(nums[l1] < nums[l2]) temp.push_back(nums[l1++]);
            else temp.push_back(nums[l2++]);
        }
        while(l1 <= m) temp.push_back(nums[l1++]);
        while(l2 <= r) temp.push_back(nums[l2++]);
        for(int i = l; i <= r; i++){
            nums[i] = temp[i-l];
        }
    }
};