class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == "") return 0;
        int hLen = haystack.length();
        int nLen = needle.length();
        int index = 0;
        int count = 0;
        while(index < hLen){
            if(haystack[index] == needle[count]){
              while(haystack[index] == needle[count]){
                if(count == nLen - 1){
                    return index - nLen + 1;
                }
                count ++;
                index ++; 
                }
                index -= count;
            }
            
            count = 0;
            index ++;
        }
        return -1;
    }
};