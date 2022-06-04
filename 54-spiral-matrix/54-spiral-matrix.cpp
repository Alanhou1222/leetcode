class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int boundRight = matrix[0].size() - 1;
        int boundBottom = matrix.size() - 1;
        int boundLeft = 0;
        int boundTop = 0;
        int i = 0;
        int j = 0;
        int direction = 0;
        vector<int> ans;
        ans.push_back(matrix[i][j]);
        while(boundLeft <= boundRight and boundBottom >= boundTop){
            switch(direction){
                case 0:
                    while(j<boundRight){
                        j++;
                        ans.push_back(matrix[i][j]);
                    }
                    boundTop++;
                    direction = 1;
                    break;
                case 1:
                    while(i<boundBottom){
                        i++;
                        ans.push_back(matrix[i][j]);
                    }
                    boundRight--;
                    direction = 2;
                    break;
                case 2:
                    while(j>boundLeft){
                        j--;
                        ans.push_back(matrix[i][j]);
                    }
                    boundBottom--;
                    direction = 3;
                    break;
                case 3:
                    while(i>boundTop){
                        i--;
                        ans.push_back(matrix[i][j]);
                    }
                    boundLeft++;
                    direction = 0;
                    break;
            }
        }
        return ans;
    }
};