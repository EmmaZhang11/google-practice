/*
 randomSet，支持insert, contains, remove, popRandom，每个操作都是O(1)
 
 思路：用unordered_set 支持insert, contains, remove 不支持popRandom
 
 popRandom需要用一个类数组的结构，支持随机访问。这里用一个vector，生成0~n-1之间的随机数k，去掉第k个数，通常vector remove的时间是O(n)，这里使用一个trick，remove kth element后把第n-1个元素移动到k位置上，更新数组的长度和unordered_set。
 
 算法：unordered_map<int> mp, vector<int> vec
 
 insert: mp[ele] =  idx_n,  vec.push_back(ele)
 
 contains: mp.contains(ele)
 
 remove: vec[mp[ele]] = vec[n-1]， n--,  t = vec[mp[ele]],  mp[t] = mp[ele], mp.erase(ele);
 
 popRandom: random k     ele = vec[k]  remove(ele)
 
*/


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
private:
    unordered_map<int,int> mp;
    vector<int> vec;
public:
    void insert(int ele){
        mp[ele] = vec.size();
        vec.push_back(ele);
    }
    
    bool contains(int ele){
        return mp.find(ele) != mp.end();
    }
    
    void remove(int ele){
        vec[mp[ele]] = vec[vec.size()-1];
        vec.resize(vec.size()-1);
        int ne = vec[mp[ele]];
        mp[ne] = mp[ele];
        mp.erase(ele);
    }
    
    int popRandom(){
        srand(unsigned(time(0)));
        int k = rand() % vec.size();
        int ans = vec[k];
        remove(mp[vec[k]]);
        return ans;
    }
};


int main()
{
    Solution s;
    s.insert(1);
    s.insert(4);
    s.insert(8);
    s.insert(5);
    cout << s.popRandom();
    s.remove(4);
    cout << s.popRandom();
    return 0;
}
