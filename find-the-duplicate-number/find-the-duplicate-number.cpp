class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int front = 1;
        int n = nums.size() - 1;
        int back = n;
        int middle = 0;
        while(front < back){
            middle = front + (back-front)/2;
            int count = 0;
            for(int i = 0; i <= n; i++){
                if(nums[i] <= middle){
                    count ++;
                }
                if(count>middle){
                    break;
                }
            }
            if(count > middle){
                back = middle;
            }
            else{
                front = middle + 1;
            }
        }
        return front;
    }
};