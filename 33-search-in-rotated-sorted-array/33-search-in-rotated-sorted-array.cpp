class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0;
        int n = nums.size();
        int last = n-1;
        int middle = front + (last-front)/2;
        while(front < last){
            if(nums[middle] < nums[0]){
                last = middle;
            }
            else{
                front = middle + 1;
            }
            middle = front + (last-front)/2;
        }
        int pivot = (nums[0] < nums[middle]) ? 0:middle;
        if(target == nums[n-1]){
            return n-1;
        }
        else if(target < nums[n-1]){
            front = pivot;
            last = n - 1;
        }
        else{
            front = 0;
            last = pivot>0 ? pivot-1:0;
        }
        middle = front + (last-front)/2;
        while(front <= last){
            if(nums[middle] == target){
                return middle;
            }
            else if(nums[middle] < target){
                front = middle + 1;
            }
            else{
                last = middle - 1;
            }
            middle = front + (last-front)/2;
        }
        return -1;
    }
};