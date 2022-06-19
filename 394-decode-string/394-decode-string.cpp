class Solution {
public:
    string decodeString(string &str) {
        string ans = "";
        stack<char> s;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ']'){
                string temp = "";
                while(s.top() != '['){
                    temp += s.top();
                    s.pop();
                }
                s.pop();
                int times = 1;
                int count = 0;
                while(!s.empty()&&(s.top() - '0') <= 9 && (s.top() - '0') >= 0){
                    count += (s.top() - '0')*times;
                    times *= 10;
                    s.pop();
                }
                for(int j = 0; j < count; j++){
                    for(int k = temp.length()-1; k >= 0; k--){
                        s.push(temp[k]);
                    }
                }
            }
            else{
                s.push(str[i]);
            }
        }
        while(!s.empty()){
            ans = s.top() + ans;
            s.pop();
        }
        return ans;
    }
};