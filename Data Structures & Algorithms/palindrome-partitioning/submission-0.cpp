class Solution {
public:
void Recursion(vector<string>& vec,vector<vector<string>>& ans,string s,int idx)
{
    if(idx==s.size())
    {
        ans.push_back(vec);
        return;
    }
    for(int i=idx;i<s.size();i++)
    {
        if(isPalindrome(idx,i,s))
        {
            vec.push_back(s.substr(idx,i-idx+1));
            Recursion(vec,ans,s,i+1);
            vec.pop_back();
        }
    }
}
bool isPalindrome(int l,int r,string s)
{
    while(l<r)
    {
        if(s[l++]!=s[r--]) return false;
    }
    return true;
}
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        vector<vector<string>> ans;
        Recursion(vec,ans,s,0);
        return ans;
    }
};
