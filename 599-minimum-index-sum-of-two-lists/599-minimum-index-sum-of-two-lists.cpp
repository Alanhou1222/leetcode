class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int sum = 10000;
        unordered_map<string, int> restaurants;
        for(int i = 0; i < list1.size(); i++){
            restaurants[list1[i]] += i+10000;
        }
        for(int i = 0; i < list2.size(); i++){
            if(restaurants[list2[i]] != 0){
                restaurants[list2[i]] += i-10000;
            }
            else{
                restaurants[list2[i]] += 10000;
            }
        }
        for(pair<string, int> restaurant: restaurants){
            cout<<restaurant.first<<" "<<restaurant.second<<endl;
            if(restaurant.second < sum){
                ans.clear();
                sum = restaurant.second;
                ans.push_back(restaurant.first);
            }
            else if(restaurant.second == sum){
                ans.push_back(restaurant.first);
            }
        }
        return ans;
    }
};