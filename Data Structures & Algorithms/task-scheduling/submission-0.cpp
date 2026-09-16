class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0,c=0;
        priority_queue<int> taskq;
        queue<pair<int,int>> coolq;
        unordered_map<char,int> mpp;

        for(auto it:tasks)
        mpp[it]++;

        for(auto it:mpp)
        taskq.push(it.second);

        while(!taskq.empty() || !coolq.empty())
        {
            //Cooldown Period
            if(!coolq.empty())
            {
                pair<int,int>p=coolq.front();
                if(p.second==time)
                {
                    taskq.push(p.first);
                    coolq.pop();
                }
            }
            //Task Scheduling
            if(!taskq.empty())
            {
                int p=taskq.top();
                taskq.pop();
                p--;
                time++;
                if(p) coolq.push({p,time+n});
            }
            else time++;
        }
        return time;
    }
};
