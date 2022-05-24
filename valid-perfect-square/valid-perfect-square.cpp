class Solution {
public:
    bool isPerfectSquare(int num) {
        int front = 1;
        int back = num;
        int middle = 0;
        while(front <= back){
            middle = front + (back - front)/2;
            if((double)num/middle == middle){
                return true;
            }
            else if((double)num/middle < middle){
                back = middle - 1;
            }
            else{
                front = middle + 1;
            }
        }
        return false;
    }
};