class Solution {
public:
    int mySqrt(int x) {
        if(x==1){
            return 1;
        }
        int front = 1;
        int back = x;
        int middle = x/2;
        while(front <= back){
            if(x/middle > middle){
                front = middle +1;
                middle = (front+back)/2;
            }
            else if(x/middle < middle){
                back = middle -1;
                middle = (front+back)/2;
            }
            else{
                return middle;
            }
        }
        return front-1;
    }
};