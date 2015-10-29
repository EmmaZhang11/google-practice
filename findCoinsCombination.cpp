#include <iostream>
#include <vector>

using namespace std;
int findCoinsCombination(int target){
    int p = 0;
    while( (1 << p) <= target) p++;
    vector<vector<int>> ans(target + 1, vector<int>(p+1, 0));
    ans[0][0] = 1;
    for(int i = 0; i <= target; i++){
        for(int j = 0; j <= p; j++){
            if(i == 0) {ans[i][j] = 1; continue;}
            if(j == 0) {ans[i][j] = 0; continue;}
            int val = ans[i][j-1];
            int k = i - (1 << (j - 1));
            if(k >= 0) val += ans[k][j-1];
            k = i - 2 *(1 << (j - 1));
            if(k >= 0) val += ans[k][j-1];
            ans[i][j] = val;
        }
    }
    return ans[target][p];
}

int main ()
{
    cout << findCoinsCombination(0) << endl;
    cout << findCoinsCombination(1) << endl;
    cout << findCoinsCombination(2) << endl;
    cout << findCoinsCombination(3) << endl;
    cout << findCoinsCombination(4) << endl;
    cout << findCoinsCombination(5) << endl;
    return 0;
}
