class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int array[20001] = {0};
        for(int &num:nums){
            array[num+10000]++;
        }
        int count = 0;
        int sum = 0;
        for(int i = 0, pick = 0; i < 20001; i++){
            if(array[i] != 0){
                if(pick%2 == 0){
                    sum += i-10000;
                    count++;
                }
                pick ++;
                array[i]--;
                i--;
            }
        }
        return sum;
    }
};