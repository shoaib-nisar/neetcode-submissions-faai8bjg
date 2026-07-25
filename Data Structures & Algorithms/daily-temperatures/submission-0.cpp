class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack<pair<int,int>> st;
      vector<int> vec(temperatures.size(),0);
      int i=0;
      while(i<temperatures.size())
      {
        if(st.empty() || st.top().first>=temperatures[i])
        {
          st.push({temperatures[i],i});
          i++;
        }
        else{
          vec[st.top().second]=i-st.top().second;
          st.pop();
        }
      }
      return vec;  
    }
};
