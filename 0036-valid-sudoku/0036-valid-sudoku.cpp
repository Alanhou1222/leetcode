class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<short int> row;
        unordered_set<short int> column;
        unordered_set<short int> box;
        for(short int i = 0; i < 9; i++){
            for(short int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(row.find((i+1)*9+(board[i][j]-'0')) != row.end()  || column.find((j+1)*9+(board[i][j]-'0')) != column.end() || box.find(((i/3)*3+(j/3)+1)*9+(board[i][j]-'0')) != box.end()){
                    return false;
                }
                else{
                    row.insert((i+1)*9+(board[i][j]-'0'));
                    column.insert((j+1)*9+(board[i][j]-'0'));
                    box.insert(((i/3)*3+(j/3)+1)*9+(board[i][j]-'0'));
                }
            }
        }
        return true;
    }
};