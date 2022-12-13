class Solution {
public:
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
 
    string minRemoveToMakeValid(string s) 
    {
        int n=s.size();
        int c=0,x=0;
        stack<int>st;
        stack<int>vec;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(i);
            if(s[i]==')') 
            {
                if(st.empty()) vec.push(i);
                else st.pop();
            }
        }
       string k;
        for(int i=n-1;i>=0;i--)
        {
           int a=-1;
           if(!st.empty()) a=st.top();
           int b=-1;
           if(!vec.empty()) b=vec.top();
           if(i==a) st.pop();
           else if (i==b) vec.pop();
           else
           k.push_back(s[i]);

        }
        reverseStr(k);
        return k;
    }
};
