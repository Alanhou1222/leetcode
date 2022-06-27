class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
        solve(0,0,n,"",ans);
        return ans;
    }
    
    void solve(int starts, int ends, int n, string s, vector<string> &ans){
        if(starts + ends == 2*n){
            ans.push_back(move(s));
            return;
        } 
        if(starts < n) solve(starts+1, ends, n, s+"(", ans);
        if(ends < starts) solve(starts, ends+1, n, s+")", ans);
    }
};