class Solution {
public:
    int mySqrt(int x) {
        long int longX = x;
        if(x==1){
            return 1;
        }
        long int front = 1;
        long int back = longX;
        long int middle = longX/2;
        while(front <= back){
            if(middle* middle < longX){
                front = middle +1;
                middle = (front+back)/2;
            }
            else if(middle* middle > longX){
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