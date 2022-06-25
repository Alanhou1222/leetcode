class Solution {
private:
    vector<int> vec1D;
    vector<vector<int>> vec2D;
    vector<vector<vector<int>>> vec3D;
    bool solved;
public:
    Solution(): vec1D(9,0), vec2D(9,vec1D), vec3D(9,vec2D), solved(false){
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    placeOrRemoveNum(i, j, board[i][j] - '0', 1);
                }
            }
        }
        solve(board, 0, 0);
    }
    
    void solve(vector<vector<char>>& board, int row, int col){
        if(solved) return;
        if(board[row][col] == '.'){
            for(int i = 0; i < 9; i++){
                if(vec3D[row][col][i] == 0){
                    board[row][col] = i + '1'; 
                    placeOrRemoveNum(row, col, i+1, 1);
                    if(row == 8 && col == 8){
                        solved = true;
                        return;
                    }
                    if(col < 8) solve(board, row, col+1);
                    else solve(board, row+1, 0);
                    if(solved) return;
                    placeOrRemoveNum(row, col, i+1, -1);
                    board[row][col] = '.';
                }
            }
        }
        else{
            if(row == 8 && col == 8){
                solved = true;
                return;
            }
            if(col < 8) solve(board, row, col+1);
            else solve(board, row+1, 0);
        }
        
    }
    
    void placeOrRemoveNum(int row, int col, int val, int direction){
        int boxRow = row/3;
        int boxCol = col/3;
        for(int i = boxRow*3; i < (boxRow+1)*3; i++){
            for(int j = boxCol*3; j < (boxCol+1)*3; j++){
                vec3D[i][j][val-1] += direction;
            }
        }
        for(int i = 0; i < 9; i++){
            if(i >= (boxRow+1)*3 || i < boxRow*3) vec3D[i][col][val-1] += direction;
            if(i >= (boxCol+1)*3 || i < boxCol*3) vec3D[row][i][val-1] += direction;
        }
        
    }
    
    
};
