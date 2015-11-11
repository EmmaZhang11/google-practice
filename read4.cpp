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
                buf[cnt++] = buffer[i];
            if(cur != 4 || cnt == n) break;
        }
        
        return cnt;
    }
    
    // Input: "a", [read(0),read(1),read(2)]  Expected: ["","a",""]
    // if last read is not dividable by 4, we should record the last read 4 bytes.
    int read2(char *buf, int n) {
        int cnt = 0;
        while(cnt < n){
            if(bPtr == 0)   //no chars left in buffer last read
                bCnt = read4(buffer);
            if(bCnt == 0) break; //end of file
            while(cnt < n && bPtr < bCnt)
                buf[cnt++] = buffer[bPtr++];
            if(bPtr == bCnt) bPtr = 0;
        }
        return cnt;
    }
    
private:
    int bPtr, bCnt;
    char buffer[4];
};

int main()
{
    return 0;
}
