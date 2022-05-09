class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> index;
        for(int i = 0; i < s.length(); i++){
            if(index[s[i]]=='\0'){
                index[s[i]] = t[i];
            }
            else if(index[s[i]] != t[i]){
                return false;
            }
        }
        unordered_map<char,int> index2;
        for(int i = 0; i < s.length(); i++){
            if(index2[t[i]]=='\0'){
                index2[t[i]] = s[i];
            }
            else if(index2[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
};