class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int pse=0,nse=0,maxArea=0;

        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int elem=heights[st.top()]; st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();

                maxArea=max(elem*(nse-pse-1),maxArea);
            }
            st.push(i);
        }

        while(!st.empty())
        {
            int elem=heights[st.top()];
            st.pop();
            nse=heights.size();
            pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,elem*(nse-pse-1));
        }
        return maxArea;
    }
};
