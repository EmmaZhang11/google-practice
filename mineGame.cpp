//实现一个扫雷游戏, 主要是实现两个函数
//(1) 给定长和宽，以及雷的数量，随机生成一个扫雷的游戏
//(2) 点击一个坐标，返回是否踩到雷，并更新游戏状态

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct point{
        int val;
        bool visible;
        point(): val(0), visible(false){}
    };
    
    vector<vector<point>> matrix;
    int m, n, cnt, k;
    
    
    void build(int m, int n, int k){
        this->m = m;
        this->n = n;
        this->k = k;
        cnt = 0;
        matrix = vector<vector<point>> (m,vector<point>(n));
        srand(unsigned(time(0)));
        for(int i = 0; i < k; i++){
            int r = rand() % (m*n);
            if(matrix[r/n][r%n].val == -1)
                i--;
            else
                matrix[r/n][r%n].val = -1;
        }
        
        int c[3] = {-1, 0, 1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j].val == 0){
                    int val = 0;
                    for(int s = 0; s < 3; s++){
                        for(int t = 0; t < 3; t++){
                            if(i + c[s] >= 0 && i + c[s] < m && j + c[t] >= 0 && j + c[t] < n)
                                if( matrix[i+c[s]][j+c[t]].val == -1)
                                    val++;
                        }
                    }
                    matrix[i][j].val = val;
                }
            }
        }
        return;
    }
    
    void dfs(int i, int j){
        if(matrix[i][j].visible) return;
        if(matrix[i][j].val > 0){
            matrix[i][j].visible = true;
            cnt++;
            return;
        }
        if(matrix[i][j].val == 0){
            matrix[i][j].visible = true;
            cnt++;
            int c[3] = {-1, 0, 1};
            for(int s = 0; s < 3; s++){
                for(int t = 0; t < 3; t++){
                    if(i + c[s] >= 0 && i + c[s] < m && j + c[t] >= 0 && j + c[t] < n)
                        dfs(i + c[s], j + c[t]);
                }
            }
        }
        return;
    }
    
    string play(int i, int j){
        if(matrix[i][j].val == -1){
            matrix[i][j].visible = true;
            return "fail";
        }
        dfs(i, j);
        if(cnt == m*n - k) return "win";
        return "continue";
    }
    
    void print(){
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j].visible)
                    cout << matrix[i][j].val;
                else cout << "v";
            }
            cout << endl;
        }
    }
    
    void printOrigin(){
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j].val << " ";
            }
            cout << endl;
        }

    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    s.build(5,5, 4);
    s.printOrigin();
    int i,j;
    while(1){
        cout << "input the place:" << endl;
        cin >> i >> j;
        string res = s.play(i,j);
        s.print();
        if(res == "win"){
            cout << "you win!" << endl;
            break;
        }
        else if(res == "fail"){
            cout << "you fail!" << endl;
            break;
        }
    }

    return 0;
}

