//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long long int n=v.size();
        long long int a1 = firstOcc(v, n, x);
        long long int a2 = lastOcc(v, n, x);
        
         pair<long,long> p(a1,a2);
         return p;
    }
    
    long long int firstOcc(vector<long long> arr, long long int n , long long x)
    {
    int low=0,high=n-1;
    int res1=-1;
        while(low<= high)
        {
            long long int mid = low+(high-low)/2;
            if(x==arr[mid])
            {
res1=mid;
               high=mid-1;
            }
            else if(x < arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res1;
    }
    long long int lastOcc(vector<long long> arr, long long int n ,long long x){
        long long int low=0,high=n-1;
         long long int res2 =  -1;
        while(low<= high)
        {
            long long int mid = low+(high-low)/2;
            if(x==arr[mid])
            {
               res2=mid;
               low=mid+1;
            }
            else if(x > arr[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res2;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends