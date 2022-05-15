class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        sort(words[0].begin(), words[0].end());
        string prev = words[0];
        for(int i = 1; i < words.size(); i++){
            string temp = words[i];
            sort(words[i].begin(), words[i].end());
            if(words[i] == prev){
                continue;
            }
            else{
                ans.push_back(temp);
                prev = words[i];
            }
        }
        return ans;
    }
};