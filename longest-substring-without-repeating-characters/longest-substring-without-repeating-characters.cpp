class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1;
        if(s.length()==1){
            return 1;
        }
        unordered_map<char, int> umap;
        int answer = 0;
        for(int i = 0; i<s.length();i++){
            if(umap.find(s[i])!=umap.end()&&umap[s[i]]>start){
                start = umap[s[i]];
            }
            answer = max(answer,i-start);
            umap[s[i]] = i;
        }
        return answer;
    }
};