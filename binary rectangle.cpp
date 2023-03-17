//https://leetcode.com/problems/maximal-rectangle/description/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>vec(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=m-1 && matrix[i][j]=='1') vec[i][j]=vec[i+1][j]+1;
                else if(matrix[i][j]=='1') vec[i][j]=1;
                else vec[i][j]=0;
            }
        }
        long long int mi=0;
        for(int i=m-1;i>=0;i--)
        {
            vector<long long >vecf(n,-1);
        vector<long long >vecb(n,n);
        stack<int>stf;
        stack<int>stb;
        for(int j=0;j<n;j++)
        {
            while(!stf.empty() && vec[i][stf.top()]>=vec[i][j]) stf.pop();
            if(!stf.empty()) vecf[j]=stf.top();
            stf.push(j);
        }
        for(int j=n-1;j>=0;j--)
        {
            while(!stb.empty() && vec[i][stb.top()]>=vec[i][j]) stb.pop();
            if(!stb.empty()) vecb[j]=stb.top();
            stb.push(j);
        }
        for(int j=0;j<n;j++)
        {
            mi=max(mi,(vecb[j]-vecf[j]-1)*vec[i][j]);
        }
        }
        return mi;
    }
};
