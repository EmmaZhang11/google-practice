//给了一个word和一个字典，问删除word中最少的字符，使得删除后的单词在字典中出现过。比如：doog可以变成dog, do, 返回dog。

#include <iostream>
#include <unordered_set>

using namespace std;

size_t deleteMinChar(string word, unordered_set<string> &dict ){
    unordered_set<string> candicates;
    unordered_set<string> candicates2;
    candicates.insert(word);
    while(!candicates.empty()){
        for(auto c : candicates){
            if(dict.find(c) != dict.end())
                return word.size() - c.size();
            for(int i = 0; i < c.size(); i++){
                string tmp = c;
                tmp.erase(tmp.begin() + i);
                if(!tmp.empty())
                    candicates2.insert(tmp);
            }
        }
        candicates = candicates2;
        candicates2.clear();
    }
    return word.size();
}

int main(int argc, const char * argv[]) {
    unordered_set<string> dict = {"google", "ibm","gooogle"};
    int cnt = deleteMinChar("gooogle", dict);
    return 0;
}
