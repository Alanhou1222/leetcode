class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string ans = "";
        int len = strs[0].length();
        int strsSize = strs.size();
        for(int i = 0; i < len; i++){
            for(int j = 0; j < strsSize; j++){
                if(strs[j].length() <= index||strs[j][index] != strs[0][index]){
                    return ans;
                }
            }
            ans += strs[0][index];
            index ++;
        }
        return ans;
    }
};