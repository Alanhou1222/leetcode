class Solution {
public:
    int climbStairs(int n) {
        int C[2] = {1,2};
        for(int i=2;i<n;i++){
            C[i%2] = C[0]+C[1];
        }
        return C[(n-1)%2];
    }
};