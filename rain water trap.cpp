//https://leetcode.com/problems/trapping-rain-water/description/
class Solution {
public:
    int trap(vector<int>& heights) 
    {
        int n=heights.size();
        vector<int>maxl(n);
        vector<int>maxr(n);
        maxl[0]=heights[0];
        maxr[n-1]=heights[n-1];
        for(int i=1;i<n;i++) maxl[i]=max(maxl[i-1],heights[i]);
        for(int i=n-2;i>=0;i--) maxr[i]=max(maxr[i+1],heights[i]);
        long long int sum=0;
        for(int i=0;i<n;i++)  sum=sum+(min(maxl[i],maxr[i])-heights[i]);
        return sum;
    }
};
