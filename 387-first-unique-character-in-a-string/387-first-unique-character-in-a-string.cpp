class Solution {
public:
    int firstUniqChar(string s) {
        int index = INT_MAX;
        unordered_map<char,int> mp;
        for(int i = 0; i<s.length(); i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = i;
            }
            else{
                mp[s[i]] = -1;
            }
        }
        for(pair<char,int> charPair:mp){
            if(charPair.second != -1){
                index = min(index, charPair.second);
            }
        }
        if(index == INT_MAX){
            return -1;
        }
        return index;
    }
};