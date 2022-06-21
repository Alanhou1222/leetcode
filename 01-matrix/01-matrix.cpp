class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int maxH = mat.size(), maxW = mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0 ; i < maxH; i++){
            for(int j = 0; j < maxW; j++){
                if(mat[i][j] == 0) q.push({i,j});
                else mat[i][j] = -1;
            }
        }
        int dist = 0;
        while(!q.empty()){
            int qSize = q.size();
            dist ++;
            for(int i = 0; i < qSize; i++){
                int f = q.front().first, s = q.front().second;
                q.pop();
                if(f > 0){
                    if(mat[f-1][s] == -1){
                        mat[f-1][s] = dist;
                        q.push({f-1,s});
                    }
                }
                if(f < maxH - 1){
                    if(mat[f+1][s] == -1){
                        mat[f+1][s] = dist;
                        q.push({f+1,s});
                    }
                }
                if(s > 0){
                    if(mat[f][s-1] == -1){
                        mat[f][s-1] = dist;
                        q.push({f,s-1});
                    }
                }
                if(s < maxW - 1){
                    if(mat[f][s+1] == -1){
                        mat[f][s+1] = dist;
                        q.push({f,s+1});
                    }
                }
            }
        }
        return mat;
    }
};