class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int m) {
        int d[105][105]; 
        for(int i=0; i<105; i++){
        for(int j=0; j<105; j++){
            d[i][j]=1e9;
        }
      }
        for(int i=0;i<times.size();i++){
            int a,b,w;
            a=times[i][0];
            b=times[i][1];
            w=times[i][2];
            d[a][b]=w;
        }
        
         for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
        int mx=0;
        for(int i=1; i<=n; i++){
            if(i!=m){
             mx=max(mx,d[m][i]);   
            }
       }
        return (mx==1e9?-1:mx);
    }
};