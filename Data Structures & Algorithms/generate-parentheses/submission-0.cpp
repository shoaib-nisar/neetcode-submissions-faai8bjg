class Solution {
public:
    void Recursion(string s,int o,int c,int n,vector<string>& vec)
    {
        if(o==c && o==n)
        {
            vec.push_back(s);
            return;
        }
        if(o<n)
        Recursion(s+"(",o+1,c,n,vec);
        if(o>c)
        Recursion(s+")",o,c+1,n,vec);
    }
    vector<string> generateParenthesis(int n) {
        string s ="";
        vector<string> vec;
        Recursion(s,0,0,n,vec);
        return vec;
    }
};
