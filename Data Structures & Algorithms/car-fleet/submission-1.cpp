class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        stack<pair<int,int>> st;

        for(int i=0;i<position.size();i++)
        {
          vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end());
        int i=speed.size()-1;
        while(i>=0)
        {
           if(!st.empty() && ((target-st.top().first)/(double)st.top().second)>=((target-vec[i].first)/(double)vec[i].second))
           {
             i--;
           }
           else st.push({vec[i]});
        }
        int c=0;
        while(!st.empty())
        {
          c++;
          st.pop();
        }
        return c;
        
    }
};
