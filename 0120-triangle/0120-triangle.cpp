class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> sum(triangle.size(), INT_MAX);
        sum[0] = 0;
        for(int i = 0; i < triangle.size(); i++)
        {
            for(int j = i; j > 0; j--)
            {
                sum[j] = triangle[i][j] + min(sum[j-1], sum[j]);
            }
            sum[0] += triangle[i][0];
        }
        return *min_element(sum.begin(), sum.end());
    }
};