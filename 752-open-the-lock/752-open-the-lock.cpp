class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end()), visited({"0000"});
        visited.insert("0000");
        queue<string> q;
        q.push("0000");
        int ans = 0;
        if(dead.find("0000") != dead.end()) return -1;
        if(target == "0000") return 0;
        while(!q.empty()){
            int qSize = q.size();
            ans++;
            for(int i = 0; i < qSize; i++){
                for(int i = 0; i < 4; i++){
                    for(string &next:turnBackOrForthByIndex(q.front(), i)){
                        if(next == target) return ans;
                        if(dead.find(next) == dead.end() && visited.find(next) == visited.end()){
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
    
    vector<string> turnBackOrForthByIndex(string& str, int index){
        vector<string> vec(2,str);
        vec[0][index] = (vec[0][index] - '0' + 1) % 10 + '0';
        vec[1][index] = (vec[1][index] - '0' + 9) % 10 + '0';
        return vec; 
    }
};