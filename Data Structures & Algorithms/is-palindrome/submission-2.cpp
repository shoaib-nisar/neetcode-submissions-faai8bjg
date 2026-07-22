class Solution {
public:
    bool isPalindrome(string s) {
    
    string str="";
    for(auto it:s)
    {
        if(isalnum(it))
        str+=tolower(it);
    }
    int l=0,r=str.size()-1;
     while(l<=r)
     {
        if(str[l++]!=str[r--])
        return false;
     }   
     return true;
    }
};
