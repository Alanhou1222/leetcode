class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1&& nums[0] == target){
            return 0;
        }
        int front = 0;
        int end = nums.size()-1;
        int middle = nums.size()/2;
        while(front <= end){
            if(nums[middle] < target){
                front = middle+1;
                middle = (front + end)/2;
            }
            else if(nums[middle] > target){
                end = middle-1;
                middle = (front + end)/2;
            }
            else{
                return middle;
            }
        }
        return -1;
    }
};