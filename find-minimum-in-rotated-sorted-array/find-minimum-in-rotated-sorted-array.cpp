class Solution {
public:
    int findMin(vector<int>& nums) {
        int front = 0;
        int back = nums.size()-1;
        int middle = front + (back-front)/2;
        while(front < back){
            // cout<<front<<" "<<middle<<" "<<back<<endl;
            if(nums[middle] < nums[0]){
                back = middle;
            }
            else if (nums[middle] == nums[0]){
                if(nums.size() > 1 && nums[middle] > nums[middle+1]){
                    front = middle + 1;
                }
                else{
                    back = middle;
                }
            }
            else{
                front = middle + 1;
            }
            middle = front + (back-front)/2;
        }
        if(nums[middle] > nums[0]){
            middle = 0;
        }
        return nums[middle];
    }
};