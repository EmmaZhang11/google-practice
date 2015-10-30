#include <iostream>
#include <queue>

using namespace std;

/*
一个board矩阵，标记0为空白区域，-1为障碍，2为食物，1为蛇身
在当前移动方向上，如果是障碍或是蛇身，蛇死亡，return false; 如果是0,则return true, 同时蛇身长度不变，在当前方向移动；如果是2，则return true，同时蛇身长度加1
如何记录蛇身，用一个snakeHead来记录蛇头位置，采用queue记录当前蛇身的轨迹，同时还需要刷新board上的标记
前方0： queue.push当前位置，pop出蛇尾，更新snakeHead,更新board的标记
前方-1 1 : 死亡
前方2： queue.push当前位置，更新snakeHead，更新board该位置的标记
 */

class greedySnake{
    int m, n;  //board row and col
    int board[10][10];
    queue<pair<int,int>> q; 
    pair<int,int> head;
private:
    bool Movement(int direction){ // 1234 上下左右
        pair<int,int> cur;
        if(direction == 1){ //up
            if(head.first-1 >= 0)
                cur = make_pair(head.first-1, head.second);
            else
                return false;
        }
        else if(direction == 2){
            if(head.first+1 < m)
                cur = make_pair(head.first+1, head.second);
            else
                return false;
            
        }
        else if(direction == 3){
            if(head.second-1 >= 0)
                cur = make_pair(head.first, head.second-1);
            else
                return false;
        }
        else {
            if(head.second+1 < n)
                cur = make_pair(head.first, head.second+1);
            else
                return false;
        }
        if(board[cur.first][cur.second] == -1 || board[cur.first][cur.second] == 1 )
            return false;
        if(board[cur.first][cur.second] == 0){
            q.push(cur);
            head = cur;
            board[cur.first][cur.second] = 1;
            pair<int,int> tmp = q.front();
            board[tmp.first][tmp.second] = 0;
            q.pop();
        }
        else{  //board[cur.first][cur.second] == 2
            q.push(cur);
            head = cur;
            board[cur.first][cur.second] = 1;
        }
        return true;
    }
};

int main ()
{
    return 0;
}
