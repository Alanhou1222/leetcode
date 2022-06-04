class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int first = 0;
        int second = 0;
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        bool up = true;
        while(first != m - 1 or second != n - 1){
            if(up){
                while(first > 0 && second < n - 1){
                    ans.push_back(mat[first][second]);
                    first--;
                    second++;
                }
                ans.push_back(mat[first][second]);
                up = false;
                if(second == n - 1){
                    first ++;
                }
                else{
                    second ++;
                }
            }
            else{
                while(first < m - 1 && second > 0){
                    ans.push_back(mat[first][second]);
                    first++;
                    second--;
                }
                ans.push_back(mat[first][second]);
                up = true;
                if(first == m - 1){
                    second ++;
                }
                else{
                    first ++;
                }
            }
        }
        ans.push_back(mat[first][second]);
        return ans;
    }
};