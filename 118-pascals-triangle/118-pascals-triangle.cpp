class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++){
            int count = 0;
            while(count < i){
                if(count == 0){
                    ans[i].push_back(1);
                }
                else{
                    ans[i].push_back(ans[i-1][count-1]+ans[i-1][count]);
                }
                count++;
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};