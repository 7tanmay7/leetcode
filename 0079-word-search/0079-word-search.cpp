class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int idx) {
        if (idx == word.size()) return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false;
        if (board[row][col] != word[idx]) return false;

        char temp = board[row][col];
        board[row][col] = '#'; // mark as visited

        // Explore 4 directions
        bool found = dfs(board, word, row + 1, col, idx + 1) ||
                     dfs(board, word, row - 1, col, idx + 1) ||
                     dfs(board, word, row, col + 1, idx + 1) ||
                     dfs(board, word, row, col - 1, idx + 1);

        board[row][col] = temp; // unmark

        return found;
    }
};