class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {

        auto it=lower_bound(mpp[key].begin(),mpp[key].end(),make_pair(timestamp,string("")));
        return (it!=mpp[key].end() && it->first==timestamp )? it->second:((it == mpp[key].begin())?"": (--it)->second);
    }
};
