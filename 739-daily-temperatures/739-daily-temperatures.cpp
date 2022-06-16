class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i = n - 1; i >= 0 ; i--){
            int days = 0;
            if(!s.empty()){
                days ++;
                while(s.top().first <= temperatures[i]){
                    days += s.top().second;
                    s.pop();
                    if(s.empty()){
                        days = 0;
                        break;
                    }
                }
            }
            s.push({temperatures[i],days});
            ans[i] = days;
        }
        return ans;
    }
};