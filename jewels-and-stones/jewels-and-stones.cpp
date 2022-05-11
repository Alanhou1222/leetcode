class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, bool> isJewel;
        int ans = 0;
        for(char jewel:jewels){
            isJewel[jewel] = true;
        }
        for(char stone:stones){
            if(isJewel[stone]){
                ans++;
            }
        }
        return ans;
    }
};