//给了一个matrix，每个matrix[i][j]有一个价格，给你一个budget，问如何求出最大面积的子矩阵，使得子矩阵的价格之和不超过budget


class Solution {
public:
    vector<int> findClosetBudget(vector<int> &matrix, int budget) {
        vector<int> ans; // 返回矩阵的左上角x1, y1, 右下角x2, y2
        int m = matrix.size();
        if(matrix.size() == 0) return ans;
        int n = matrix[0].size();

        vector<vector<int>> nums(m + 1, vector<int>(n +　1, 0));
        for(int i = 1; i <= m; i++){
            int tmp = 0;
            for(int j = 1; j <= n; j++){
                tmp += matrix[i-1][j-1];
                nums[i][j] = num[i-1][j] + tmp;
            }
        }

        int v = INT_MAX;
        int ii = 0, jj = 0, kk = 0, nn = 0;
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                vector<int> tmp(n + 1, 0);
                for(int k = 1; k <= n; k++)
                    tmp[k] = nums[j][k] - nums[i][k];
                int nxt = 0;
                for(int k = 0; k <= n ; k++){
                    while(tmp[nxt] - tmp[k] <= target && nxt <= n)
                        nxt++;
                    nxt--;
                    if(tmp[nxt] - tmp[k] < v){
                        v = tmp[nxt] - tmp[k];
                        ii = i;
                        jj = j;
                        kk = k;
                        nn = nxt;
                    }
                    nxt++;
                }
            }
        }

        ans.push_back(i);
        ans.push_back(k);
        ans.push_back(j + 1);
        ans.push_back(nn + 1);
        return ans;
    }
};