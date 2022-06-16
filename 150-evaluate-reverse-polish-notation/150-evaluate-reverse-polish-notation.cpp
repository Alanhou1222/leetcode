class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(string &str:tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int b = stoi(s.top());
                s.pop();
                int a = stoi(s.top());
                s.pop();
                if(str == "+") s.push(to_string(a+b));
                else if(str == "-") s.push(to_string(a-b));
                else if(str == "*") s.push(to_string(a*b));
                else s.push(to_string(a/b));
            }
            else{
                s.push(str);
            }
        }
        return stoi(s.top());
    }
};