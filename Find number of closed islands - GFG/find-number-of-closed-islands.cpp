//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int row,int col,vector<vector<int>> & matrix,vector<vector<int>> & vis){
        int n=matrix.size();
        int m=matrix[0].size();
        vis[row][col]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && matrix[nrow][ncol]==1){
                dfs(nrow,ncol,matrix,vis);
            }
        }
    }
    
    public:
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==1){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(matrix[i][m-1]==1){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        
        for(int j=0;j<m;j++){
            if(matrix[0][j]==1){
                vis[0][j]=1;
                q.push({0,j});
            }
            if(matrix[n-1][j]==1){
                vis[n-1][j]=1;
                q.push({n-1,j});
            }
        }
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && matrix[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && matrix[i][j]==1){
                    dfs(i,j,matrix,vis);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends