class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int low=0,high=nums1.size(),mid=0,tot=nums1.size()+nums2.size();
       while(low<=high)
       {
        mid=(low+high)/2;
        int n1=mid,n2=(tot)/2 - n1;
        int l1=(n1==0)?INT_MIN:nums1[n1-1];
        int l2=(n2==0)?INT_MIN:nums2[n2-1];
        int r1=(n1==nums1.size())?INT_MAX:nums1[n1];
        int r2=(n2==nums2.size())?INT_MAX:nums2[n2];

        if(l1>r2) high=mid-1;
        else if(l2>r1) low=mid+1;
        else
        return (tot%2==0)?(double)(max(l1,l2)+min(r1,r2))/2:(min(r1,r2));
       } 
    }
};
