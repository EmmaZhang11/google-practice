//给一个字符串，该字符串由一些可能会重复的字符组成，重新排列这个字符串使得没有相邻的字符是相同字符。如aab变成aba


string charDiffentNeighbor(string input)
{
    if(input.size() < 3) return input;
    map<char, int> mp;
    for(int i = 0; i < input.size(); i++)
        mp[input[i]]++;
    
    priority_queue<pair<int, char>> pq; //default as minHeap
    for(auto it : mp)
        pq.push(make_pair(it.second, it.first));
    
    string output;
    char c;
    int cnt = 0;
    while(!pq.empty()){
        pair<int,char> it = pq.top();
        pq.pop();
        output += it.second;
        if(cnt != 0)
            pq.push(make_pair(cnt, c));
        c = it.second;
        cnt = --it.first;
    }
    if(cnt > 0) output += c;
    return output;
}
