class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans ++;
                    clear(grid, i, j);
                }
            }
        }
        return ans;
    }
    void clear(vector<vector<char>>& grid, int row, int column){
        if(row<0||row>=grid.size()||column<0||column>=grid[0].size()||grid[row][column]=='0'){
            return;
        }
        grid[row][column] = '0';
        clear(grid, row-1, column);
        clear(grid, row+1, column);
        clear(grid, row, column-1);
        clear(grid, row, column+1);
    }
};

