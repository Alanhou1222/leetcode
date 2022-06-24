class Solution {
public:
    int totalNQueens(int n) {
        vector<int> vec1D(n,0);
        vector<vector<int>> vec2D(n,vec1D);
        return backTrack(vec2D, n, 0, 0);
    }
    int backTrack(vector<vector<int>> &vec, int n, int row, int count){
        for(int col = 0; col < n; col++){
            if(vec[row][col] == 0){
                modifyVector(vec, n, row, col, 1);
                if(row+1 == n) count ++;
                else count = backTrack(vec, n, row+1, count);
                modifyVector(vec, n, row, col, -1);
            }
        }
        return count;
    }
    void modifyVector(vector<vector<int>> &vec, int n, int row, int col, int sign){
        for(int j = 0; j < n; j++){
            vec[row][j] += sign;
            vec[j][col] += sign;
        }
        int x = row, y = col;
        while(x > 0 && y > 0){
            x--;
            y--;
        }
        while(x < n && y < n){
            vec[x][y] += sign;
            x++;
            y++;
        }
        x = row;
        y = col;
        while(x > 0 && y < n-1){
            x--;
            y++;
        }
        while(x < n && y >= 0){
            vec[x][y] += sign;
            x++;
            y--;
        }
        vec[row][col] -= sign*3;
    }
};