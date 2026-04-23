class Solution {
public:
    // going from left side column to right column so checkinf on the lefter
    // portion always
    bool validPos(vector<string> board, int n, int row, int col) {
        // checking row - moving columns
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q')
                return false;
        }

        // column always free because we placing in column as we proceed

        // checking diagonally in top left and bottom left

        // top left
        int i = row - 1;
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        // bottom left
        i = row + 1;
        j = col - 1;
        while (i <= n - 1 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }

        return true;
    }

    bool valid(vector<int> &topToBottom, vector<int> &bottomToTop, int n, int row, int col, vector<int> &ro) {
        if (topToBottom[((2*n + 1)/2) + col - row -1]) return false;
        if (bottomToTop[row + col]) return false;
        if (ro[row]) return false;
        return true;
    }

    void f(vector<vector<string>>& ans, vector<string>& board, int n, int col,
           vector<int>& topToBottom, vector<int>& bottomToTop, vector<int> &ro) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (valid(topToBottom, bottomToTop, n, i, col, ro)) {
                board[i][col] = 'Q';

                topToBottom[((2*n + 1)/2) + col - i-1] = 1;
                bottomToTop[i + col] = 1;
                ro[i] = 1;

                f(ans, board, n, col + 1, topToBottom, bottomToTop, ro);
                board[i][col] = '.';

                topToBottom[((2*n + 1)/2) + col - i-1] = 0;
                bottomToTop[i + col] = 0;
                ro[i] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string st(n, '.');
        vector<string> board(n, st);

        vector<int> topToBottom(2 * n - 1, 0);
        vector<int> bottomToTop(2 * n - 1, 0);
        vector<int> ro(n, 0);

        f(ans, board, n, 0, topToBottom, bottomToTop, ro);
        return ans;
    }
};class Solution {
public:
    // going from left side column to right column so checkinf on the lefter
    // portion always
    bool validPos(vector<string> board, int n, int row, int col) {
        // checking row - moving columns
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q')
                return false;
        }

        // column always free because we placing in column as we proceed

        // checking diagonally in top left and bottom left

        // top left
        int i = row - 1;
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        // bottom left
        i = row + 1;
        j = col - 1;
        while (i <= n - 1 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }

        return true;
    }

    bool valid(vector<int> &topToBottom, vector<int> &bottomToTop, int n, int row, int col, vector<int> &ro) {
        if (topToBottom[((2*n + 1)/2) + col - row -1]) return false;
        if (bottomToTop[row + col]) return false;
        if (ro[row]) return false;
        return true;
    }

    void f(vector<vector<string>>& ans, vector<string>& board, int n, int col,
           vector<int>& topToBottom, vector<int>& bottomToTop, vector<int> &ro) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (valid(topToBottom, bottomToTop, n, i, col, ro)) {
                board[i][col] = 'Q';

                topToBottom[((2*n + 1)/2) + col - i-1] = 1;
                bottomToTop[i + col] = 1;
                ro[i] = 1;

                f(ans, board, n, col + 1, topToBottom, bottomToTop, ro);
                board[i][col] = '.';

                topToBottom[((2*n + 1)/2) + col - i-1] = 0;
                bottomToTop[i + col] = 0;
                ro[i] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string st(n, '.');
        vector<string> board(n, st);

        vector<int> topToBottom(2 * n - 1, 0);
        vector<int> bottomToTop(2 * n - 1, 0);
        vector<int> ro(n, 0);

        f(ans, board, n, 0, topToBottom, bottomToTop, ro);
        return ans;
    }
};