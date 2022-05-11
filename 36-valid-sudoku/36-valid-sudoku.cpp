class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, bool> row;
        unordered_map<int, bool> column;
        unordered_map<int, bool> box;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(  row[(i+1)*9+(board[i][j]-'0')] == true
                   ||column[(j+1)*9+(board[i][j]-'0')] == true
                   ||box[((i/3)*3+(j/3)+1)*9+(board[i][j]-'0')] == true){
                    return false;
                }
                else{
                    row[(i+1)*9+(board[i][j]-'0')] = true;
                    column[(j+1)*9+(board[i][j]-'0')] = true;
                    box[((i/3)*3+(j/3)+1)*9+(board[i][j]-'0')] = true;
                }
            }
        }
        return true;
    }
};