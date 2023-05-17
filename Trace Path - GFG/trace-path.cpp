//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int t_l =  0; int t_r= 0; int t_u =0; int t_d=0;// max consecutive l,r,ud
        int f_lr =0; int f_ud=0;
            for(int i = 0;i < s.length();i++){
        if(s[i] == 'L')
                f_lr++;
            else if(s[i] == 'R')
                f_lr--;
            else if(s[i] == 'U')
                f_ud++;
            else
                f_ud--;
                
                if(f_lr>=0) //more left than right
                t_l = max(t_l, f_lr);
                else
                t_r = min(t_r, f_lr);
                
                if(f_ud>=0) t_u = max(t_u, f_ud);
                else t_d =min(t_d, f_ud);
            }
        if(t_l-t_r<m && t_u-t_d<n)
        return 1;
        
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends