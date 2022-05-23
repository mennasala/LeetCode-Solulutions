class Solution {
public:
vector<string>v;
int dp[605][105][105];
int solve(int idx, int m, int n){
	if (idx >= v.size())
		return 0;
	int &ret = dp[idx][m][n];
	if (~ret)
		return ret;
	int zer = count(v[idx].begin(), v[idx].end(), '0');
	int on = count(v[idx].begin(), v[idx].end(), '1');
	if (zer <= m && on <= n){
		ret = max(ret, solve(idx + 1, m - zer, n - on) + 1); 
	}
	ret = max(ret, solve(idx + 1, m, n));
	return ret;
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof dp);
        for(auto it:strs)
            v.push_back(it);
        return solve(0,m,n);
    }
};