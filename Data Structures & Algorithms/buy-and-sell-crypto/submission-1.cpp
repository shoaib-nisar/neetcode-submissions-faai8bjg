class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=0,maxP=0,p=0;
        while(r!=prices.size())
        {
            p=prices[r]-prices[l];
            if(p>=0) r++;
            else l++;
            maxP=max(maxP,p);
        }
        return maxP;
    }
};
