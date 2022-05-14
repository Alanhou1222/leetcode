/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int front = 1;
        int back = n;
        int middle = front + (back - front)/2;
        while(front <= back){
            middle = front + (back - front)/2;
            if(guess(middle)==0){
                return middle;
            }
            else if(guess(middle) == -1){
                back = middle - 1;
            }
            else{
                front = middle + 1;
            }
            
        }
        return -1;
    }
};