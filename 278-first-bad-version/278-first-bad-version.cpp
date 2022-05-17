// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int front = 1;
        int back = n;
        int middle = front + (middle-front)/2;
        while(front < back){
            if(isBadVersion(middle)){
                back = middle;
            }
            else{
                front = middle + 1;
            }
            middle = front + (back-front)/2;
        }
        return front;
    }
};