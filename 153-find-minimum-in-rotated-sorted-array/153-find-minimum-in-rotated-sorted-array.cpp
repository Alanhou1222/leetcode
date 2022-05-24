class Solution {
public:
    int findMin(vector<int>& nums) {
        int front = 0;
        int back = nums.size()-1;
        int middle = 0;
        int min = nums[0];
        while(front < back){
            middle = front + (back - front)/2;
            if(nums[middle] < min){
                min = nums[middle];
                back = middle;
            }
            else{
                front = middle + 1;
            }
        }
        back = (nums[back] < nums[0]) ? back:0;
        return nums[back];
    }
};