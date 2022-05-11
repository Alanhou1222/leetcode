class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string &str:strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        for(pair<string, vector<string>> kVPair:mp){
            ans.push_back(kVPair.second);
        }
        return ans;
    }
};