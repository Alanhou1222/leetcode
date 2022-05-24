class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int front = 0;
        int back = letters.size();
        int middle = -1;
        while(front < back){
            middle = front + (back-front)/2;
            if(letters[middle] > target){
                back = middle;
            }
            else{
                front = middle + 1;
            }
        }
        back = (letters[back] > target) ? back:0;
        return letters[back];
    }
};