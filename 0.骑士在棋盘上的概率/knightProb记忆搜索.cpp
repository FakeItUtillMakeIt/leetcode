class Solution {
public:
    //八个方向
    vector<pair<int, int>> directions = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
    double knightProbability(int N, int K, int r, int c) {
        //board[row][col][j]用于存储在row行，col列走j步不出界的概率
        vector<vector<vector<double>>> board(N, vector<vector<double>>(N, vector<double>(K + 1, 0)));
        return nextStep(board, N, K, r, c, K);
    }
    //step代表的是还需要走的步数，[nowRow][nowCol]是现在的位置
    double nextStep(vector<vector<vector<double>>> &board, int N, int K, int nowRow, int nowCol, int step){
        if (nowRow < 0 || nowCol < 0 || nowRow >= N || nowCol >= N){//出界
            return 0;
        }
        //如果此时step == 0，代表它已经不能移动，所以没有出界的概率就是1.0
        if (step == 0){
            return 1.0;
        }
        //如果这个点之前搜索过，（注意double类型不能直接判断board[nowRow][nowCol][step] == 0，需要判断它是否小于一个很小的值，比如1e-6）
        if (abs(board[nowRow][nowCol][step]) > 1e-6){
            return board[nowRow][nowCol][step];
        }
        //穷举八个方向
        for (auto &direction : directions){
            board[nowRow][nowCol][step] += nextStep(board, N, K, nowRow + direction.first, nowCol + direction.second, step - 1) / 8;
        }
        return board[nowRow][nowCol][step];
    }
};