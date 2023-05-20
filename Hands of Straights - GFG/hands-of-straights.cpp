//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
    if (N % groupSize != 0) {
        return false;
    }
    
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        m[hand[i]]++;
    }
    
    while (!m.empty()) {
        int a = m.begin()->first;
        
        for (int j = 0; j < groupSize; j++) {
            int b = a + j;
            if (m.find(b) == m.end()) {
                return false;
            }
            
            m[b]--;
            if (m[b] == 0) {
                m.erase(b);
            }
        }
    }
    
    return true;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends