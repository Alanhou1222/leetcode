class Solution {
public:
    int findMin(vector<int>& nums) {
        int front = 0;
        int back = nums.size()-1;
        int middle = 0;
        while(front < back){
            middle = front + (back-front)/2;
            if(nums[front] < nums[back]){
                return nums[front];
            }
            if(nums[middle] > nums[back]){
                front = middle + 1;
            }
            else{
                back--;
            }
        }
        return nums[front];
    }
};