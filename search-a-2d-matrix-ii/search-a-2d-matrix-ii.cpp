class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix[0].size()-1;
        int y = 0;
        while(x >= 0 && y < matrix.size()){
            if(matrix[y][x] == target) return true;
            if(matrix[y][x] < target) y++;
            else if(matrix[y][x] > target) x--;
        }
        return false;
    }
};