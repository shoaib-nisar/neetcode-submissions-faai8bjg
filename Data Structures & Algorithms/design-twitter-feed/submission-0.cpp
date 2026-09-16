class Twitter {
public:
    unordered_map<int,unordered_set<int>> mpp;
    priority_queue<pair<int,pair<int,int>>> pq;
    queue<pair<int,pair<int,int>>> q;
    int feed;
    Twitter() {
        feed=0;
    }
    
    void postTweet(int userId, int tweetId) {
        feed++;
        pq.push({feed,{userId,tweetId}});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> vec;
        while(!pq.empty() && vec.size()!=10)
        {
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            q.push(p);

            if(p.second.first==userId || mpp[userId].count(p.second.first))
            vec.push_back(p.second.second);  
        }

        while(!q.empty()){
        pair<int,pair<int,int>> p=q.front();
        pq.push(p); 
        q.pop(); 
        }

        return vec;
    }
    
    void follow(int followerId, int followeeId) {
        mpp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mpp[followerId].erase(followeeId);
    }
};
