class MinStack {
    struct Node{
        int val;
        Node* next;
    };
    Node* last;
    int minVal;
public:
    MinStack(): last(nullptr), minVal(INT_MAX) {
    }
    
    void push(int val) {
        Node* temp = last;
        last = new Node();
        last->next = temp;
        last->val = val;
        minVal = min(minVal,val);
    }
    
    void pop() {
        if(last->val == minVal){
            Node* temp = last->next;
            minVal = INT_MAX;
            while(temp){
                minVal = min(minVal,temp->val);
                temp = temp->next;
            }
        }
        last = last->next;
    }
    
    int top() {
        return last->val;
    }
    
    int getMin() {
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