class Solution {
public:
    int firstUniqChar(string s) {
        int ans = INT_MAX;
        vector<int> charArray(26,-1);
        for(int i = 0; i<s.length(); i++){
            if(charArray[s[i]-'a'] == -1){
                charArray[s[i]-'a'] = i;
            }
            else{
                charArray[s[i]-'a'] = -2;
            }
        }
        for(int index:charArray){
            if(index >= 0){
                ans = min(ans, index);
            }
        }
        return ans == INT_MAX ? -1:ans;
    }
};