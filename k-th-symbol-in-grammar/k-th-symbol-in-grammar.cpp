class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1){
            return 0;
        }
        int prevNum = kthGrammar(n-1, (k+1)/2);
        if(k%2==0){
            if(prevNum == 0){
                return 1;
            }
            return 0;
        }
        return prevNum;
    }
};