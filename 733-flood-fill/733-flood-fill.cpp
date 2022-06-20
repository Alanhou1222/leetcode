class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        helper(image,sr,sc,color,image[sr][sc]);
        return image;
    }
    
    void helper(vector<vector<int>>& image, int sr, int sc, int color, int oldColor){
        if(sr < 0 || sc < 0 || sr >= image.size()|| sc >= image[0].size() || color == image[sr][sc]) return;
        if(image[sr][sc] == oldColor){
            image[sr][sc] = color;
            helper(image,sr-1,sc,color,oldColor);
            helper(image,sr+1,sc,color,oldColor);
            helper(image,sr,sc-1,color,oldColor);
            helper(image,sr,sc+1,color,oldColor);
        }
        
    }
};