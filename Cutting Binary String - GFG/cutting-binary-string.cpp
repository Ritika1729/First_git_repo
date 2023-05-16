//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool isPowfive(string s){
        long long num=0;
        for(int i=0; i<s.size(); i++){
            num=num*2+(s[i]-'0');
        }
        
        if(num==0)return false;
        while(num>1){
            if(num%5!=0)return false;
            num/=5;
        }
        return true;
    }
    int cuts(string s){
        //code
        if(s.size()==0||s[0]=='0')return -1;
        if(isPowfive(s))return 1;
        int minCut=INT_MAX;
        for(int i=1; i<s.size(); i++){
            string left=s.substr(0,i);
            string right=s.substr(i);
            if(isPowfive(left)){
                int cutsRight=cuts(right);
                if(cutsRight!=-1)minCut=min(minCut,cutsRight+1);
            }
        }
        if(minCut==INT_MAX)return -1;
        
        return minCut;
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends