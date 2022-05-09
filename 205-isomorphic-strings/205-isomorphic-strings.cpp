class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> index;
        for(int i = 0; i < s.length(); i++){
            if(index[s[i]]==0){
                index[s[i]] = t[i]-'0';
            }
            else if(index[s[i]] != t[i]-'0'){
                return false;
            }
        }
        unordered_map<char,int> index2;
        for(int i = 0; i < s.length(); i++){
            if(index2[t[i]]==0){
                index2[t[i]] = s[i]-'0';
            }
            else if(index2[t[i]] != s[i]-'0'){
                return false;
            }
        }
        return true;
    }
};