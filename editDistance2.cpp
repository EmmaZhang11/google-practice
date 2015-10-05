int editDistance2(string s1, string s2){
	int n = s1.size(), m = s2.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for(int i = 0; i <= n; i++) dp[i][0] = i;
	for(int i = 0; i <= m; i++) dp[0][i] = i;
	for(int i = 1; i <= n; i++){
		int v = INT_MAX;
		for(int j = 1; j <= m; j++){
			v = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
			if(s1[i] == s2[j]) v = min(v, dp[i-1][j-1]);
			else v = min(v, dp[i-1][j-1]+1);
			if(i >= 2 && j >= 2 && s1[i] == s2[j-1] && s1[i-1] == s2[j] && s1[i] != s2[j])
				v = min(v, dp[i-2][j-2]+1);
		}
		dp[i][j] = v;
	}
	return dp[n][m];
}
