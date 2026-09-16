class MedianFinder {
public:
int n;
priority_queue<int> pq;
priority_queue<int,vector<int>,greater<int>> pq2;
    MedianFinder() {
       n=0; 
    }
    
    void addNum(int num) {
       n++; 
       if(pq.size()!=n/2+1)
       {
            if(!pq2.empty() && pq2.top()<num)
            {
                pq.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }else
            pq.push(num);
       }
       else if(num<pq.top())
       {
            pq2.push(pq.top());
            pq.pop();
            pq.push(num);
       }else pq2.push(num);
    }
    
    double findMedian() {
        if(n==0) return 0.0;
        double m;
        if(n%2==0)
        {
            int x=pq.top();
            pq.pop();
            m=(x+pq.top())/2.0;
            pq.push(x);
        }
        else m=pq.top();

        return m;
    }
};
