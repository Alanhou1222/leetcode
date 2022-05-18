class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int front = 0;
        int n = nums.size();
        int back = n - 1;
        int middle = front + (back-front)/2;
        if( n==1 || nums[front]>nums[front+1]){
            return 0;
        }
        if(nums[back]>nums[back-1]){
            return back;
        }
        while(front<=back){
            if(nums[middle]>nums[middle-1]&&nums[middle]>nums[middle+1]){
                return middle;
            }
            if(nums[middle]<nums[middle-1]){
                back = middle;
            }
            else{
                front = middle + 1;
            }
            middle = front + (back-front)/2;
        }
        return -1;
    }
};