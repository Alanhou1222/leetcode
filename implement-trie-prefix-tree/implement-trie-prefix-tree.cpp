class Trie {
    struct TreeNode{
        TreeNode* next[26];
        bool isEnd;
    };
    TreeNode* root;
public:
    Trie(): root(new TreeNode()) {
    }
    
    void insert(string word) {
        TreeNode* temp = root;
        for(char c:word){
            if(temp->next[c-'a'] == nullptr){
                temp->next[c-'a'] = new TreeNode();
            }
            temp = temp->next[c-'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TreeNode* temp = root;
        for(char c: word){
            if(temp->next[c-'a'] == nullptr) return false;
            temp = temp->next[c-'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreeNode* temp = root;
        for(char c: prefix){
            if(temp->next[c-'a'] == nullptr) return false;
            temp = temp->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */