/*
 给定字母和摩尔密码的映射关系。
(1) 将一个字符串转换成摩尔密码。
(2) 摩尔密码不是前缀码，给定一组单词，输出歧义码的组数。
例如air和rue的摩尔密码相同，还给了另外两个word，摩尔密码各不同，{air, rue, word1, word2}输出1。
(3) 给定摩尔密码，输出该摩尔密码可能解析成的所有字符串。
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

string stringtoCode(string origin, unordered_map<char, string> mooreCode){
    string ans;
    for(int i = 0; i < origin.size(); i++)
        ans += mooreCode[origin[i]];
    
    return ans;
}


int duplicateGroup(vector<string> words, unordered_map<char, string> mooreCode){
    unordered_map<string, int> cnt;
    for(auto word : words){
        string mooreString = stringtoCode(word, mooreCode);
        cnt[mooreString]++;
    }
    
    int ans = 0;
    for(auto c : cnt){
        if(c.second > 1) ans++;
    }
    return ans;
}

void help(string &moore, int start, unordered_map<string, char> &mooreToChar, string &ans, vector<string> &res){
    if(start == moore.size()){
        res.push_back(ans);
        return;
    }
    for(int i = start; i < moore.size(); i++){
        string s = moore.substr(start, i - start + 1);
        if(mooreToChar.find(s) != mooreToChar.end()){
            ans += mooreToChar[s];
            help(moore, i + 1, mooreToChar, ans, res);
            ans.resize(ans.size() - 1);
        }
    }
}

vector<string> decodeMoore(string moore,unordered_map<char, string> mooreCode){
    unordered_map<string, char> mooreToChar;
    for(auto mc : mooreCode)
        mooreToChar[mc.second]  = mc.first;
    vector<string> res;
    string ans;
    help(moore, 0, mooreToChar, ans, res);
    return res;
}
