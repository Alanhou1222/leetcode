class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target, int x = -2, int y = 0) {
        if(x == -2) x = matrix[0].size()-1;
        if(x < 0 || y >= matrix.size()) return false;
        if(matrix[y][x] == target) return true;
        if(matrix[y][x] < target) return searchMatrix(matrix, target, x, y+1);
        return searchMatrix(matrix, target, x-1, y);
    }
};