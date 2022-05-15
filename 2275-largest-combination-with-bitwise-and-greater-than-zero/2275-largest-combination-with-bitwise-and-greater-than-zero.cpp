class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(32,0);
        for(int num: candidates){
            for(int i = 0; i < 32; i++){
                if(num % 2 == 1){
                    count[i] ++;
                }
                if(num > 0){
                    num /= 2;
                }
                else{
                    break;
                }
            }
        }
        int ans = 0;
        for(int num:count){
            ans = max(ans, num);
        }
        return ans;
    }
};