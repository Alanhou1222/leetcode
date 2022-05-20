class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1,-1};
        }
        int front = 0;
        int back = nums.size()-1;
        int middle = front + (back-front)/2;
        while(front <= back){
            if(nums[middle] == target){
                break;
            }
            else if(nums[middle] <= target){
                front = middle + 1;
            }
            else{
                back = middle - 1;
            }
            middle = front + (back-front)/2;
        }
        if(front <= back){
            int firstMiddle = middle;
            int first = front + (firstMiddle - front)/2;
            while(front <= firstMiddle){
                if(nums[first] == target && (first == 0 || nums[first-1] != target)){
                    break;
                }
                else if(nums[first] < target){
                    front = first + 1;
                }
                else{
                    firstMiddle = first - 1;
                }
                first = front + (firstMiddle - front)/2;
            }
            int last = middle + (back - middle)/2;
            while(middle <= back){
                if(nums[last] == target && (last == nums.size()-1 || nums[last+1] != target)){
                    break;
                }
                else if(nums[last] <= target){
                    middle = last + 1;
                }
                else{
                    back = last - 1;
                }
                last = middle + (back - middle)/2;
            }
            return{first, last};
        }
        return {-1, -1};
    }
};