class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> vec;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp[val] != 0){
            return false;
        }
        vec.push_back(val);
        mp[val] = vec.size();
        return true;
    }
    
    bool remove(int val) {
        if(mp[val] == 0){
            return false;
        }
        vec[mp[val]-1] = vec.back();
        mp[vec.back()] = mp[val];
        vec.pop_back();
        mp[val] = 0;
        return true;
        
    }
     
    int getRandom() {
        int randNum = rand() % vec.size();
        return vec[randNum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */