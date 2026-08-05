class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        for (int i = 0; i < N; i++) {
            map<char, bool> mp;
            for (char c : board[i]) {
                if (c == '.') continue;
                if (mp[c]) return false;
                mp[c] = true;
            }
            mp.clear();
            for (int j = 0; j < N; j++) {
                char c = board[j][i];
                if (c == '.') continue;
                if (mp[c]) return false;
                mp[c] = true;
            }
        }   
        for (int i = 0; i < N; i += 3) {
            for (int j = 0; j < N; j += 3) {
                map<char, bool> mp;
                for (int k = i; k < i + 3; k++) {
                    for (int z = j; z < j + 3; z++) {
                        char c = board[k][z];
                        if (c == '.') continue;
                        if (mp[c]) return false;
                        mp[c] = true;
                    }
                }
            }
        }
        return true;
    }
};
