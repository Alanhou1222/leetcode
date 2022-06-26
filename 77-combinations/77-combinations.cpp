class Solution {
private:
    int N;
    int K;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        N = n;
        K = k;
        vector<int> empty;
        backTrack(ans, empty, 1);
        return ans;
    }
    
    void backTrack(vector<vector<int>> &ans, vector<int> &cur, int next){
        for(int i = next; i <= N; i++){
            if(N - next >= (K - cur.size() - 1)){
                cur.push_back(i);
                if(cur.size() == K){
                    ans.push_back(cur);
                }
                else backTrack(ans, cur, i+1);
                cur.pop_back();
            }
            else{
                return;
            }
        }
    }
};