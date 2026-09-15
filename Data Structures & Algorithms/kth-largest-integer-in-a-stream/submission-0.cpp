class KthLargest {
public:
    int cap;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
     cap=k;
     for(auto it:nums)
     {
        if(pq.size()==cap)
        {
            if(pq.top()<it){
            pq.pop();
            pq.push(it);}
        }else
        pq.push(it);
     }
    }
    
    int add(int val) {
        if(pq.size()==cap)
        {
            if(pq.top()<val){
            pq.pop();
            pq.push(val);}
        }else
        pq.push(val);
    return pq.top();
    }
};
