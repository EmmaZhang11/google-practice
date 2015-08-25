/*
1-n之间   其中某些数能表示为 两个立方数的和  求这样的数的个数
x = a^3 + b^3    x = c^3 + d^3  x为满足条件的一个数 
ab这组和cd这组不一样
*/

int cubeGroupCount(int n){
	int k = pow(n, 1/ 3.0);
	vector<int> res(k+1, 0);
	for(int i = 1; i <= k; i++)
		res[i] = i*i*i;
	unordered_map<int,int> mp;
	for(int i = 0; i <= k; i++){
		for(int j = i; j <= k; j++){
			int v = res[i] + res[j];
			mp[v]++；
		}
	}
	int count = 0;
	for(auto it = mp.begin(); it != mp.end(); it++)
		if(it->second > 1) count++;
	return count;
}
