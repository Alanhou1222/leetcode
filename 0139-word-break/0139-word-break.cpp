class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> canSeg(s.length(), false);
        unordered_set set(wordDict.begin(), wordDict.end());
        for(int i = 0; i < s.length(); i++)
        {
            int j = 0;
            while(j <= i)
            {
                string temp;
                temp = s.substr(j, i - j + 1);
                if(set.find(temp) != set.end())
                {
                    canSeg[i] = true;
                    break;
                }
                while(j <= i && !canSeg[j]) j ++;
                j++;
            }
        }
        for(int i = 0; i < canSeg.size(); i++)
        {
            cout << (int)canSeg[i] << " ";
        }
        return canSeg.back();
    }
};