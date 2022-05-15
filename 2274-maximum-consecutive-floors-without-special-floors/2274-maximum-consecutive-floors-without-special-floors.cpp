class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        // unordered_map<int, int> mp;
        // for(int floor: special){
        //     mp[floor] = 1;
        // }
        // int maxNum = 0;
        // int count = 0;
        // for(int i = bottom; i <= top; i++){
        //     if(mp[i] != 1){
        //         count++;
        //         maxNum = max(maxNum, count);
        //     }
        //     else{
        //         count = 0;
        //     }
        // }
        // return maxNum;
        sort(special.begin(), special.end());
        int maxNum = special[0] - bottom;
        for(int i = 1; i < special.size(); i++){
            maxNum = max(maxNum, (special[i] - special[i-1] - 1));
        }
        maxNum = max(maxNum, (top - special.back()));
        return maxNum;
    }
};