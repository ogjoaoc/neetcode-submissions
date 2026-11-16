class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {

    };

    void push(int val) {
        if (empty(this->st)) {
            this->st.push({val, val});
            return;
        }        
        this->st.push({val, min(val, this->st.top().second)});
    }
    
    void pop() {
        this->st.pop();
    }
    
    int top() {
        return this->st.top().first;
    }
    
    int getMin() {
        return this->st.top().second;
    }
};
