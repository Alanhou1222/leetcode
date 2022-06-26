class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> empty;
        backTrack(ans, empty, 1, n, k);
        return ans;
    }
    
    void backTrack(vector<vector<int>> &ans, vector<int> &cur, int next, int &N, int &K){
        for(int i = next; i <= N; i++){
            if(N - next >= (K - cur.size() - 1)){
                cur.push_back(i);
                if(cur.size() == K){
                    ans.push_back(cur);
                }
                else backTrack(ans, cur, i+1, N, K);
                cur.pop_back();
            }
            else{
                return;
            }
        }
    }
};