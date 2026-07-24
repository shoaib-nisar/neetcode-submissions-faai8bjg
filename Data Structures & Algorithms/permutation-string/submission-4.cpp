class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int l=0,r=0;
      vector<int> arr1(26,0);
      vector<int> arr2(26,0);

      for(auto it: s1)
      arr1[it-'a']++;

      while(r!=s2.size())
      {
        arr2[s2[r]-'a']++;
         if(r-l+1==s1.size())
         {
            if(arr1==arr2) return true;
            arr2[s2[l]-'a']--;
            l++;
         }
          r++;
      }
      return false;
    }
};
