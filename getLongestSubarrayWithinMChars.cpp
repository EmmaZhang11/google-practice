#include <iostream>
#include <vector>

using namespace std;

int getLongestSubarrayWithinMChars(string stream, int m){
    int cnt = 0;
    vector<int> pos(256, -1);     //存储字符出现的最近的位置
    int ans = 0;
    int start = 0;
    for(int i = 0; i < stream.size();){
        while(cnt <= m && i < stream.size()){
            char tmp = stream[i];
            if(pos[tmp] == -1) cnt++;
            pos[tmp] = i;
            i++;
        }
        ans = max(ans, i - start - 1);
        int mi = -1;
        //找出pos中值最小的，这里可以优化
        for(int j = 0; j < 256; j++){
            if(pos[j] != -1 && (mi == -1 || pos[j] < pos[mi]))
                mi = j;
        }
        cnt--;
        start = pos[mi] + 1;
        pos[mi] = -1;
    }
    return ans;
}

int main()
{
    cout << getLongestSubarrayWithinMChars("abcdca", 2); // 3
    cout << getLongestSubarrayWithinMChars("abcdcababc", 2); //4
    cout << getLongestSubarrayWithinMChars("abdabcabcdac", 3); //6

    return 0;
}
