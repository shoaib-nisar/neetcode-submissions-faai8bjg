class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
         vector<vector<int>> vec;
        for(int i=0;i<points.size();i++)
        {
            int d= (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            if(pq.size()==k)
            {
                if(pq.top().first>d)
                {
                    pq.pop();
                    pq.push({d,i});
                }
            }else
            pq.push({d,i});
        }

        while(!pq.empty())
        {
            vec.push_back(points[pq.top().second]);
            pq.pop();
        }
        return vec;
    }
};
