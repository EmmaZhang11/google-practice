#include <iostream>
#include <cmath>
#include <algorithm> // swap
#include <unordered_set>
#include <vector>

using namespace std;
int factorSum(int k){
    int sum = 0;
    for(int i = 1; i < sqrt(k); i++){
        if(k % i == 0){
            sum = sum + i;
            if(k / i < k) sum = sum + k / i;
        }
    }
    int kk = sqrt(k);
    if(kk * kk == k) sum += kk;
    return sum;
}

int findBeijingCircle(int n){
    int ans = 0;
    vector<bool> v(n+1, false);
    for(int i = 1; i <= n; i++){
        if(v[i] == true) continue;
        unordered_set<int> set;
        int s = i;
        while(s <= n && set.find(s) == set.end()){
            set.insert(s);
            v[s] = true;
            s = factorSum(s);
            if(s == 1) break;
        }
        if(s != 1 && s <=n ){
            set.clear();
            vector<int> tmp;
            while(set.find(s) == set.end()){
                set.insert(s);
                tmp.push_back(s);
                s = factorSum(s);
            }
            if(set.size() > ans){
                for(auto ii : tmp) cout << ii << " ";
                cout << endl;
            }
            ans = max(ans, (int)set.size());
        }
    }
    return ans;
}


int main()
{
    cout << findBeijingCircle(1000000);
    //共28个 14316 19116 31704 47616 83328 177792 295488 629072 589786 294896 358336 418904 366556 274924 275444 243760 376736 381028 285778 152990 122410 97946 48976 45946 22976 22744 19916 17716
    cout << factorSum(17716);
    return 0;
}
