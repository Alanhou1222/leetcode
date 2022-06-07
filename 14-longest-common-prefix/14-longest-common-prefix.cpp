class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = 200;
        for(string str: strs){
            minLen = min(minLen, int(str.length()));
        }
        int index = 0;
        string ans = "";
        char x = ' ';
        while(index < minLen){
            x = strs[0][index];
            for(string str: strs){
                if(str[index] != x){
                    return ans;
                }
            }
            ans += x;
            index ++;
        }
        return ans;
    }
};