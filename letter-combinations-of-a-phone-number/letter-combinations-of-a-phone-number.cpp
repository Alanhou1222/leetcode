class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        vector<string> numToWord;
        numToWord = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<int> num;
        vector<string> answer;
        answer.push_back("");
        for(int i = 0;i<digits.length();i++){    
            vector<string> temp;
            for(string s: answer){
                for(int j = 0;j<numToWord[digits[i]-'0'].length();j++){
                    temp.push_back(s+numToWord[digits[i]-'0'][j]);
                }
            }
            answer = temp;
        }
        return answer;
    }
};