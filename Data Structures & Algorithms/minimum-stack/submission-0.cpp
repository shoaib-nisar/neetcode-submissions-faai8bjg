class MinStack {
public:
    int min=INT_MAX;
    stack<int> mst;
    stack<int> st;
    MinStack() {
    }
        
    
    void push(int val) {
        st.push(val);
        if(mst.empty() || val<=mst.top())
        {
          mst.push(val);
        }
    }
    
    void pop() {
      if(st.top()==mst.top())
      mst.pop();
      st.pop();
    }
    
    int top() {
      return (!st.empty())?st.top():NULL;
    }
    
    int getMin() {
        return mst.top();
    }
};
