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
        vector<int> temp(r-l+1);
        int m = l+(r-l)/2;
        int i = l;
        int j = m + 1;
        int k = 0;
        while(i <= m && j <= r){
            if(nums[i] < nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i <= m) temp[k++] = nums[i++];
        while(j <= r) temp[k++] = nums[j++];
        for(int i = 0; i < k; i++){
            nums[i+l] = temp[i];
        }
    }
};