class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        for(int i = 0; i < len/2; i++){
            swap(s[i],s[len-i-1]);
        }
        int front = 0;
        int back = len;
        int index = 0;
         while(s[front] == ' '){
            front ++;
        }
        while(s[back-1] == ' '){
            back --;
        }
        for(int i = front; i < back;){
            if(s[i] != ' '){
                s[index] = s[i];
                i++;
            }
            else{
                while(s[i] == ' '){
                    i++;
                }
                s[index] = ' ';
            }
            index++;
        }
        int wordStart = 0;
        int wordEnd = 0;
        for(int i = 0; i < index; i++){
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
        return s.substr(0,index);
    }
};