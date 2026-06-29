class Solution {
public:

    string encode(vector<string>& strs) {
    string str="";
    for(auto it:strs)
    {
        int len=it.size();
        str+="#"+to_string(len)+"#"+it;
    }
    return str;
    }

    vector<string> decode(string s) {
        int j;
        string str="";
        vector<string> res;
        int len=0;
        for(int i=0;i<s.size();i=j+len+1)
        {
            j=i;
            if(s[j] == '#')
            {
                j+=1;
                while(s[j] != '#')
                {
                    str+=s[j];
                    j++;
                }
                len=stoi(str);
                str="";
                
            }

                res.push_back(s.substr(j+1,len));
        }
        

        return res;
    }
};
