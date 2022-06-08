class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        string comp = strs[0];
        if(strs.size()==1) return comp;
        int res=INT_MAX;
        
        for(int i=1;i<strs.size();i++){
            int l=0;
            for(int j=0;j<strs[i].size();j++){
                if(comp[j]==strs[i][j]) l++;
                else break;
            }
            res = min(res,l);
        }
        for(int i=0;i<res;i++){
            ans+=comp[i];
        }
        return ans;
    }
};