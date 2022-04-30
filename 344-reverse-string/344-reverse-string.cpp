class Solution {
public:
    void reverseString(vector<char>& s, int index = 0) {
        int length = s.size();
        if(index < length/2){
            swap(s[index],s[length-index-1]);
            reverseString(s,++index);
        }
        return;
    }
};