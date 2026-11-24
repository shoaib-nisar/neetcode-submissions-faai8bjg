class Solution {
public:
void Recursion(vector<string>& vec,int idx,string s,string digits)
{
     static const string arr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(idx==digits.size())
        {
            vec.push_back(s);
            return;
        }
     for(int i=0;i<arr[digits[idx]-'0'].size();i++)
     {
        Recursion(vec,idx+1,s+arr[digits[idx]-'0'][i],digits);
     }
}
    vector<string> letterCombinations(string digits) {
        vector<string> vec;
        string s="";
        if(!digits.size()) return vec;
        Recursion(vec,0,s,digits);
        return vec;
    }
};
