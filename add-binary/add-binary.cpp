class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int aIndex = a.length() - 1;
        int bIndex = b.length() - 1;
        int sum = 0;
        int carry = 0;
        while(aIndex >= 0 || bIndex >= 0){
            sum = carry;
            if(aIndex >= 0) sum += a[aIndex--] - '0';
            if(bIndex >= 0) sum += b[bIndex--] - '0';
            if(sum > 1){
                carry = 1;
                sum -= 2;
            }
            else{
                carry = 0;
            }
            ans = ((sum == 0) ? '0':'1') + ans;
        }
        if(carry == 1) ans = '1' + ans;
        return ans;
    }
};