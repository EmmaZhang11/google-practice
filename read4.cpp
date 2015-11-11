#include <iostream>
#include <vector>
#include <string>
using namespace std;

int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char buffer[4];
        int cnt = 0;
        while(1){
            int cur = read4(buffer);
            int len = min(cur, n - cnt);
            for(int i = 0; i < len; i++)
                buf[cnt+i] = buffer[i];
            cnt += len;
            if(cur != 4 || cnt == n) break;
        }
        
        return cnt;
    }
    
    // Input: "a", [read(0),read(1),read(2)]  Expected: ["","a",""]
    int read2(char *buf, int n) {
        //待写
        
        //return cnt;
        return 0;
    }
};

int main()
{
    return 0;
}
