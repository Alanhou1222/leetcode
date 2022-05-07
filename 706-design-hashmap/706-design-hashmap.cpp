class MyHashMap {
    unordered_map<int, int> data;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        data[key] = value+1;
    }
    
    int get(int key) {
        return data[key]-1;
    }
    
    void remove(int key) {
        data[key] = 0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */