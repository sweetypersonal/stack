//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        vector<long long >vecf(n,-1);
        vector<long long >vecb(n,n);
        stack<int>stf;
        stack<int>stb;
        for(int i=0;i<n;i++)
        {
            while(!stf.empty() && heights[stf.top()]>=heights[i]) stf.pop();
            if(!stf.empty()) vecf[i]=stf.top();
            stf.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!stb.empty() && heights[stb.top()]>=heights[i]) stb.pop();
            if(!stb.empty()) vecb[i]=stb.top();
            stb.push(i);
        }
        long long int m=0;
        for(int i=0;i<n;i++)
        {
            m=max(m,(vecb[i]-vecf[i]-1)*heights[i]);
        }
        return m;
    }
};
