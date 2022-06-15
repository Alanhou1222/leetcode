class MinStack {
    struct Node{
        int val;
        Node* next;
    };
    Node* last;
public:
    MinStack(): last(nullptr) {
    }
    
    void push(int val) {
        Node* temp = last;
        last = new Node();
        last->next = temp;
        last->val = val;
    }
    
    void pop() {
        last = last->next;
    }
    
    int top() {
        return last->val;
    }
    
    int getMin() {
        int minVal = INT_MAX;
        Node* temp = last;
        while(temp){
            minVal = min(minVal,temp->val);
            temp = temp->next;
        }
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */