class TimeMap {
public:
    unordered_map<string,map<int,string>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        int temp;
        for(auto it:mpp[key])
        {
            if(it.first>timestamp)
            {
                break;
            }
            temp=it.first;
        } 
        return mpp[key][temp];  
    }
};
