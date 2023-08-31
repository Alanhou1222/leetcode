class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        queue<vector<int>> q;
        vector<vector<int>> answer;
        for(int i = 0; i < candidates.size(); i++)
        {
            if(candidates[i] < target) q.push({candidates[i]});
            else if(candidates[i] == target)
            {
                answer.push_back({candidates[i]});
                break;
            }
            else break;
            while(!q.empty())
            {
                int qSize = q.size();
                for(int j = 0; j < qSize; j++)
                {
                    for(int k = i; k < candidates.size(); k++)
                    {
                        if(candidates[k] < q.front().back()) continue;
                        if(accumulate(q.front().begin(), q.front().end(), candidates[k]) < target)
                        {
                            vector<int> temp = q.front();
                            temp.push_back(candidates[k]);
                            q.push(temp);
                        }
                        else if(accumulate(q.front().begin(), q.front().end(), candidates[k]) > target)
                            break;
                        else
                        {
                            vector<int> temp = q.front();
                            temp.push_back(candidates[k]);
                            answer.push_back(temp);
                            break;
                        }

                    }
                    q.pop();
                }
                
            }
        }
        return answer;
    }
};