//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
  string reverseEqn (string s)
        { int i = s.length() - 1;
        string ans = "";
        
        while (i >= 0) {
            
            int num = s[i] - '0';
                
            int j = i - 1;
            int pw=1;
            while (j >= 0 && s[j] >= '0' && s[j] <= '9') {
                num += (s[j] - '0') * pow(10,pw);
                pw++;
                j -= 1;
            }
        
            ans += to_string(num);
            while(j>=0 and (s[j]<'0' or s[j]>'9')){
                 ans+=s[j];
                 j -= 1;
            }
            
            i = j;
        }
        
       
        
        return ans;
        } 
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends