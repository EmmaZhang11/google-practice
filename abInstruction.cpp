// 一个小车, 只能接受两个指令: "a":前进, 并double速度; "r":掉头, 并把速度置为1(不走)。
//初始速度为1，给一个指令串, 问最后位置. 比如"aaara", 就是正向走 1+2+4, 掉头走 1, 所以最后位置是6.
//Followup: 给定一个最终位置, 求最短的指令串.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int finalPostion(string input){
        if(input.size() == 0)return 0;
        int d = 1, cnt = 0;
        int ans = 0;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == 'r'){
                d *= -1;
                cnt = 0;
            }else{
                int tmp = 1 << cnt;
                cnt++;
                ans += tmp * d;
            }
        }
        return ans;
    }
    
    int decide(int n){
        for(int i = 0; i < 32; i++){
            if(n == ((1 << i) - 1))
                return i;
        }
        return -1;
    }
    
    int minInstruction(int position){
        //dp[len] =  min(dp[i] + dp[len - i]) i从0到len
        //dp[len] =  min(dp[i] + dp[len - i]) i从0到len/2
        //dp[len] =  min(dp[len - k] + dp[k]) k= 1， 3 ， 7， 15.....且k <= len
        int p = abs(position);
        vector<int> dp(p+1, 0);
        for(int i = 1; i <= p; i++){
            int ans = INT_MAX;
            dp[i] = decide(i);
            if(dp[i] < 0){
                for(int j = i - 1; j > 0; j--){
                    int tmp = decide(j);
                    if(tmp) ans = min(ans, tmp + dp[i-j] + 2);
                }
                dp[i] = ans;
            }
        }
        if(position > 0) return dp[p];
        else return dp[p]+1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.finalPostion("aaara") << endl;
    cout << s.minInstruction(6) << endl;
    return 0;
}
