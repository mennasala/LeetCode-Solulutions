class Solution {
public:
    bool valid(int i,int j,int n,int m){
        return i<n && i>=0 && j>=0 && j<m;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)
            return -1;
        int dx[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };
        int dy[8] = { 1, 0, -1, 0, -1, 1, 1, -1 };
        
        queue<pair<int,int>>q;
        q.push({0,0});
        int mn=1e9;
        int cost[105][105];
        bool vis[105][105];
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                cost[i][j]=1e9;
                vis[i][j]=0;
            }
        }
        int n=grid.size();
        int m=grid[0].size();
        cost[0][0]=1;
        vis[0][0]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int tox=dx[i]+x;
                int toy=dy[i]+y;
                if(valid(tox,toy,n,m) && grid[tox][toy]==0 && !vis[tox][toy]){
                    q.push({tox,toy});
                    vis[tox][toy]=1;
                    cost[tox][toy]=min(cost[tox][toy],cost[x][y]+1);
                }
                
            }
        }
        return (cost[n-1][m-1]==1e9?-1:cost[n-1][m-1]);
    }
};