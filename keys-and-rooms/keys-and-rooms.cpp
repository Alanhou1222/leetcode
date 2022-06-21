class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int count = 1;
        unordered_set<int> s;
        s.insert(0);
        for(int key: rooms[0]){
            q.push(key);
        }
        while(!q.empty()){
            if(s.find(q.front()) == s.end()){
                for(int key: rooms[q.front()]){
                    q.push(key);
                }
                s.insert(q.front());
                count++;
            }
            q.pop();
        }
        return count == rooms.size();
    }
};