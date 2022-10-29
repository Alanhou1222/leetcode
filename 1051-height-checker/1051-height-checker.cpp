class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector<int> expected = heights;
        bool hasSwap = true;
        while(hasSwap){
            hasSwap = false;
            for(int i = 0; i < expected.size()-1; i++){
                if(expected[i] > expected[i+1]){
                    hasSwap = true;
                    swap(expected[i], expected[i+1]);
                }
            }
        }
        for(int i = 0; i < expected.size(); i++){
            if(expected[i] != heights[i]) ans++;
        }
        return ans;
    }
};