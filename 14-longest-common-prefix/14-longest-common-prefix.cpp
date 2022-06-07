class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string ans = "";
        char x = ' ';
        while(index < strs[0].length()){
            x = strs[0][index];
            for(string str: strs){
                if(str.length() <= index||str[index] != x){
                    return ans;
                }
            }
            ans += x;
            index ++;
        }
        return ans;
    }
};