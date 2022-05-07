class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> appeared;
        return helper(appeared, n);
    }
    bool helper(unordered_map<int, int> &appeared, int n){
        if(n == 1){
            return true;
        }
        if(appeared[n] == -1){
            return false;
        }
        if(appeared[n] == 0){
            appeared[n] = -1;
            int next = 0;
            while(n>0){
                next += pow(n%10,2);
                n /= 10;
            }
            return helper(appeared, next);
        }
        return false;
    }
};