class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string ans = "";
        int len = strs[0].length();
        while(index < len){
            for(string str: strs){
                if(str.length() <= index||str[index] != strs[0][index]){
                    return ans;
                }
            }
            ans += strs[0][index];
            index ++;
        }
        return ans;
    }
};