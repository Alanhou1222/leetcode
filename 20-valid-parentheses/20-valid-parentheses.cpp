class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        vector<string> validPairs = {"()", "[]", "{}"};
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < 3; j++){
                if(!brackets.empty() && brackets.top() == validPairs[j][0] && s[i] == validPairs[j][1]){
                    brackets.pop();
                    break;
                }
                else if(j == 2){
                    brackets.push(s[i]);
                }
            }
            
        }
        return brackets.empty();
    }
};