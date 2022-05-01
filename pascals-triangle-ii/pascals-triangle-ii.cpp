class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if(rowIndex == 0){
            return {1};
        }
        ans = getRow(rowIndex-1);
        int temp = ans[0];
        for(int i = 1; i < rowIndex; i++){
            ans[i] = ans[i]+temp;     
            temp = ans[i]-temp;
        }
        ans.push_back(1);
        return ans;
    }
};