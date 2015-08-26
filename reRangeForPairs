#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// http://www.geeksforgeeks.org/minimum-number-of-swaps-required-for-arranging-pairs-adjacent-to-each-other/

int help(vector<int> &arr, int start, unordered_map<int, int> &mp, vector<int> &pos, int step){
	int n = arr.size();
	if (start == n || start == n - 2) return step;
	if (mp[arr[start]] == arr[start + 1]) return help(arr, start + 2, mp, pos, step);

	int p1 = pos[mp[arr[start]]];
	swap(arr[start + 1], arr[p1]);
	pos[arr[p1]] = p1;
	pos[arr[start + 1]] = start + 1;
	int result1 = help(arr, start + 2, mp, pos, step + 1);
	swap(arr[start + 1], arr[p1]);
	pos[arr[p1]] = p1;
	pos[arr[start + 1]] = start + 1;

	int p2 = pos[mp[arr[start + 1]]];
	swap(arr[start], arr[p2]);
	pos[arr[p2]] = p2;
	pos[arr[start]] = start;
	int result2 = help(arr, start + 2, mp, pos, step + 1);
	swap(arr[start], arr[p2]);
	pos[arr[p2]] = p2;
	pos[arr[start]] = start;

	return min(result1, result2);
}

int reRangeForPairs(vector<int> arr, vector<int> pairs){
	int n = arr.size();
	if (arr.size() == 0 || arr.size() == 2) return 0;
	unordered_map<int, int>  mp;
	for (size_t i = 0; i < pairs.size(); i += 2)
	{
		mp[pairs[i]] = pairs[i + 1];
		mp[pairs[i + 1]] = pairs[i];
	}

	vector<int> pos(n + 1, 0);
	for (int i = 0; i < n; i++)
		pos[arr[i]] = i;

	return help(arr,0, mp, pos, 0);
}
