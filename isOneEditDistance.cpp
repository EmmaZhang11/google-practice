#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sn = s.size(), tn = t.size();
        if(abs(sn - tn) > 1) return false;
        if(sn > tn) swap(s, t);
        bool mismatch = false;
        int i = 0, j = 0;
        for(; i < sn && j < tn; i++, j++){
            if(s[i] == t[j]) continue;
            if(mismatch) return false;
            if(sn != tn) i--;
            mismatch = true;
        }
        if(j < tn-1) return mismatch != true;
        return true;
    }
};

int main()
{
    Solution s;
    cout <<s.isOneEditDistance("asc", "abcx"); // 0
    cout <<s.isOneEditDistance("abc", "abxc"); // 1
    cout <<s.isOneEditDistance("abc", "abx");  // 1
    return 0;
}
