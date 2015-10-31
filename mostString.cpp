/*实现一个数据结构，该数据结构类似set 可以插入，删除元素，同时还有以下三个接口：1） 返回最大的字符串（字典序） 2）最小的字符串  3）返回单词出现次数最大的单词（多个的话随便返回一个就行） 
map记录string的count, set记录pair<int,string> 先擦除，再插入，保证3个操作都是O(logn) */

#include <iostream>
#include <map>
#include <set>

using namespace std;

class Dict {
private:
    map<string, int> mp;
    set<pair<int, string> > st;
public:
    Dict(){}
    void insert(string s) {
        int k = mp[s];
        mp[s]++;
        if(k > 0)
            st.erase(make_pair(k,s));
        st.insert(make_pair(k+1, s));
    }
    
    void erase(string s) {
        if(mp.find(s) == mp.end())
            return;
        int k = mp[s]--;
        if(mp[s] == 0)
            mp.erase(s);
        st.erase(make_pair(k, s));
        st.insert(make_pair(k-1, s));
    }
    
    string largeWord(){
        if(mp.empty()) return "";
        return mp.rbegin()->first;
    }
    
    string smallWord(){
        if(mp.empty()) return "";
        return mp.begin()->first;
    }
    
    string getMost() {
        if(!st.empty())
            return st.rbegin()->second;
        return "";
    }
};


int main()
{
    Dict dict;
    //string s = "abc";
    dict.insert("abs");
    dict.insert("abs");
    dict.insert("abc");
    dict.insert("xyz");

    cout << dict.largeWord() << endl;   //xyz
    cout << dict.smallWord() << endl;   //abc
    cout << dict.getMost() << endl;     //abs
        return 0;
}
