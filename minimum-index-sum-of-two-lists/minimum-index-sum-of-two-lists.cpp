class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int sum = 10000;
        unordered_map<string, int> restaurants;
        for(int i = 0; i < list1.size(); i++){
            restaurants[list1[i]] += i+1;
        }
        for(int i = 0; i < list2.size(); i++){
            if(restaurants.find(list2[i])!=restaurants.end()){
                if(restaurants[list2[i]]+i < sum){
                    ans.clear();
                    sum = restaurants[list2[i]]+i;
                    ans.push_back(list2[i]);
                }
                else if(restaurants[list2[i]]+i == sum){
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};