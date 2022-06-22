class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        vector<int> left(nums.begin(),nums.begin()+nums.size()/2);
        vector<int> right(nums.begin()+nums.size()/2,nums.end());
        left = sortArray(left);
        right = sortArray(right);
        return mergeArray(left,right);
    }
    vector<int> mergeArray(vector<int>& left, vector<int>& right){
        int leftIndex = 0, rightIndex = 0;
        vector<int> combine;
        while(leftIndex < left.size() && rightIndex < right.size()){
            if(left[leftIndex] < right[rightIndex]){
                combine.push_back(left[leftIndex++]);
            }
            else{
                combine.push_back(right[rightIndex++]);
            }
        }
        while(leftIndex < left.size()){
            combine.push_back(left[leftIndex++]);
        }
        while(rightIndex < right.size()){
            combine.push_back(right[rightIndex++]);
        }
        return combine;
    }
};