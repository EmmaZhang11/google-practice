#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool dfs(char c, unordered_map<char, int>& v, unordered_map<char, vector<char>>& graph, string& ans){
    if(v[c] == 2) return false;
    if(v[c] == 1) return true;
    v[c] = 2;
    for(char k : graph[c]){
        if(!dfs(k, v, graph, ans)) return false;
    }
    v[c] = 1;
    ans = c + ans;
    return true;
}

void makeGraph(vector<string>& words, unordered_map<char, vector<char>>& graph, unordered_set<char>& chars){
    for(int i = 0; i + 1 < words.size(); i++){
        string s1 = words[i];
        string s2 = words[i+1];
        int j = 0;
        bool find = false;
        while(j < s1.size() || j < s2.size()){
            if(j < s1.size() && graph.count(s1[j]) == 0)
                graph[s1[j]] = vector<char>();
            if(j < s2.size() && graph.count(s2[j]) == 0)
                graph[s2[j]] = vector<char>();
            if(!find && j < s1.size() && j < s2.size() && s1[j] != s2[j]){
                graph[s1[j]].push_back(s2[j]);
                find = true;
            }
            j++;
        }
    }
}

string alienOrder(vector<string>& words) {
    unordered_map<char, vector<char>> graph;
    unordered_set<char> chars;
    makeGraph(words, graph, chars);
    unordered_map<char, int> v;
    string ans;
    for(auto p : graph){
        char c = p.first;
        if(!dfs(c, v, graph, ans)) return "";

    }
    return ans;
}

int main()
{
    vector<string> words = {"wrtx", "wrf", "er", "ett", "rftt"};
    string a = alienOrder(words);
    return 0;
}
