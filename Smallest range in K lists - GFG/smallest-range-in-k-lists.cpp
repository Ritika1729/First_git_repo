//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    
    public:
    // node declare nhi hai toh node bana rhe okki linkedlist me jaise banate hai aur ek ye okk
    class Node {
        public:
        int data, row,col;
        Node(int data, int row, int col) {
            this->data = data;
            this->row = row;
            this->col = col;
        }
        
    }; 
    // aur ek ye compare struct me n=banaya  jo yaha use ho rhaok
    struct compare {
         bool operator()(Node* a,Node* b){
        return a->data >  b->data;
        }
    };
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
          //code here
          int mini=INT_MAX,maxi=INT_MIN;
    priority_queue<Node*,vector<Node*>,compare> pq;

    for(int i=0;i<k;i++){

        int element=a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        pq.push(new Node(element,i,0));
    }
    int start=mini,end=maxi;
  
    while(!pq.empty()){

        Node* temp=pq.top();
        pq.pop();
        mini=temp->data;

        if(maxi-mini < end-start){
            start=mini;
            end=maxi;
        }
    // yaha pe a likha tha jbki function me Ksorted matrix tha okii
        if(temp->col +1 <n){
            maxi=max(maxi,a[temp->row][temp->col + 1]);
            pq.push(new Node(a[temp->row][temp->col + 1]
                             ,temp->row,temp->col + 1));
        }else{
//           
            break;
        }
    }
    return make_pair(start, end);
    
    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends