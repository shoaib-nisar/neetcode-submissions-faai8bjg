class Solution {
public:
    bool isValid(string s) {
      stack<int>st;
      unordered_map<char,char> mpp;
      mpp['[']=']';
      mpp['{']='}';
      mpp['(']=')';
      for(auto it:s)
      {
        if(it=='[' || it=='{' || it=='(')
        st.push(it);
        else
        {
          if(!st.empty() && it==mpp[st.top()])
          st.pop();
          else
          return false;
        }
      }
        return (st.empty())?true:false;
    }
};
