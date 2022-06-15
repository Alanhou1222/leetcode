class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> visited;
        queue<int> q;
        vector<int> squares;
        int ans = 1;
        for(int i = 1; i*i <= n; i++){
            if(i*i == n) return ans;
            squares.push_back(i*i);
            visited.insert(i*i);
            q.push(i*i);
        }
        while(!q.empty()){
            ans ++;
            int qSize = q.size();
            for(int i = 0; i < qSize; i++){
                for(int &square:squares){
                    int sum = q.front() + square;
                    if(sum == n) return ans;
                    else{
                        if(visited.find(sum) == visited.end()){
                            visited.insert(sum);
                            q.push(sum);
                        }
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};