//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
int nextHappy(int N) {
        int nextNumber = N + 1;
        
        while (true) {
            if (isHappy(nextNumber)) {
                return nextNumber;
            }
            
            nextNumber++;
        }
    }
    
private:
    bool isHappy(int n) {
        std::unordered_map<int, int> mp;
        
        while (mp.find(n) == mp.end()) {
            mp[n] = 1;
            int sum = 0;
            
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            
            if (sum == 1) {
                return true;
            }
            
            n = sum;
        }
        
        return false;
    
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends