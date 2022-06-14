class Solution {
public:
    int wordStart = 0;
    int wordEnd = 0;
    string reverseWords(string s) {
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                wordEnd ++;
            }
            else if(wordEnd > wordStart){
                for(int j = wordStart; j < wordStart + (wordEnd - wordStart)/2; j++){
                    swap(s[j],s[wordEnd-(j-wordStart)-1]);
                }
                wordEnd = i + 1;
                wordStart = i + 1;
            }
            else{
                wordEnd++;
                wordStart++;
            }
        }
        for(int j = wordStart; j < wordStart + (wordEnd - wordStart)/2; j++){
            swap(s[j],s[wordEnd-(j-wordStart)-1]);
        }
        return s;
    }
};