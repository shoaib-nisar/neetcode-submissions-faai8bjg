class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        int maxArea=0,i=0;
        for( i=0;i<heights.size();i++)
        {
            int idx=i;
            while(!st.empty() && st.top().first>heights[i])
            {
                pair<int,int> p=st.top();
                maxArea=max(maxArea,p.first*(i-p.second));
                st.pop();
                idx=p.second;
            }
            st.push({heights[i],idx});
        }
        while(!st.empty())
        {
            pair<int,int> p=st.top();
            maxArea=max(maxArea,p.first*(i-p.second));
            st.pop();
        }

        return maxArea;
    }
};
