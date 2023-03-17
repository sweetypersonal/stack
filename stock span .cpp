//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int nums[], int n)
    {
       stack<int>st;
       vector<int>ans(n,0);
       for(int i=0;i<n;i++)
       {
           while(! st.empty() && nums[i]>=nums[st.top()]) st.pop();
           int x=-1;
           if(!st.empty()) x=st.top();
           st.push(i);
           ans[i]=i-x;
       }
       
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends
