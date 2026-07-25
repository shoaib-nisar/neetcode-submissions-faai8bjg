class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans=0;
        for(auto it:tokens)
        {
          if(it=="+" || it=="-" || it=="*" || it=="/"){
            int e2=st.top();
            st.pop();
            int e1=st.top();
            st.pop();
            if(it=="+") st.push(e1+e2);
            else if(it=="-") st.push(e1-e2);
            else if(it=="*") st.push(e1*e2);
            else if(it=="/") st.push(e1/e2);
          } else st.push(stoi(it));
        }
        return st.top();
    }
};
