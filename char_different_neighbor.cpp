//给一个字符串，该字符串由一些可能会重复的字符组成，重新排列这个字符串使得没有相邻的字符是相同字符。如aab变成aba


string charDiffentNeighbor(string input)
{
	if(input.size() < 3) return input;
	map<char, int, greater<int>> mp; //sorted as decreasing
	for(int i = 0; i < input.size(); i++)
		mp[input[i]]++;

	string output;
	char c;
	int cnt = 0;
	while(!mp.empty()){
		auto it = mp.begin();
		output += it->first;
		char tmpc = it->first;
		int tmpcnt = --it->second;
		if(cnt != 0)
			mp[c] = cnt;
		c = tmpc;
		cnt = tmpcnt;
		mp.erase(c);
	}
	if(cnt > 0) output += c;
	return output;
}
