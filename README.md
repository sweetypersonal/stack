# stack
https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=gfg&amp;utm_medium=article&amp;utm_campaign=bottom_sticky_on_article
vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long>st;
        vector<long long>vec;
        for(int i=n-1;i>=0;i--)
        {
            if(!st.empty()&&st.top()<=arr[i])
            {
                while(!st.empty()&&st.top()<=arr[i])
                {
                    st.pop();
                }
                //st.push(arr[i]);
            }
            if(st.empty()) vec.push_back(-1);
            else vec.push_back(st.top());
            st.push(arr[i]);
        }
       reverse(vec.begin(),vec.end());
        return vec;
    }
