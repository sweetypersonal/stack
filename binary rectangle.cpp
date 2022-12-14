//https://leetcode.com/problems/maximal-rectangle/description/
class Solution {
public:
 int largestRectangleArea(vector<int>& arr) 
    {
        int n=arr.size();
        stack<int>st;
        stack<int>st1;
        vector<int>vecf;
        vector<int>vecb;
        for(int i=0;i<n;i++)//least to left
        {
           if(!st.empty()&&arr[st.top()]>=arr[i])
           {
               while(!st.empty()&&arr[st.top()]>=arr[i]) 
               {
                  st.pop();
               }
           }
           if(st.empty())vecf.push_back(i);
           else vecf.push_back(i-st.top()-1);
           st.push(i);
           
        }
        for(int i=n-1;i>=0;i--)//least to right
        {

           if(!st1.empty()&&arr[st1.top()]>=arr[i])
           {
               while(!st1.empty()&&arr[st1.top()]>=arr[i]) 
               {
                  st1.pop();
               }
           }
          
           if(st1.empty())vecb.push_back(n-i-1);
           else 
           {
                cout<<st1.top()<<" "<<i<<"\n";
               vecb.push_back(st1.top()-i-1);
           }
           st1.push(i);    
        }
        reverse(vecb.begin(),vecb.end());
        int a=0,b;
        for(int i=0;i<n;i++)
        {
            //cout<<arr[i]<<" "<<vecf[i]<<" "<<vecb[i]<<"\n";
            a=max(a,(vecf[i]+vecb[i]+1)*arr[i]);
        }
        return a;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int x=0;
        vector<int>vec(m,0);
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
               if(matrix[i][j]=='1')vec[j]++;
               else vec[j]=0;
           }
           x=max(x,largestRectangleArea(vec));
        }
        return x;
    }
};
