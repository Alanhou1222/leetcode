class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int vectorSize = digits.size();
        for(int i = 0; i < vectorSize; i++){
            if(digits[vectorSize-i-1] != 9){
                digits[vectorSize-i-1]++;
                return digits;
            }
            digits[vectorSize-i-1] = 0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};