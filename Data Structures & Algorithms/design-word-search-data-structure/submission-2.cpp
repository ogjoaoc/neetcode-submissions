const int MAXN = 1e5 + 10;

class WordDictionary {
public:
    int trie[MAXN][26] = {0}; 
    bool ends_at[MAXN] = {false};
    int total_nodes = 0;
    WordDictionary() {
        
    }
    void addWord(string word) {
        int node = 0;
        for (char c : word) {
            if (trie[node][c - 'a'] == 0) {
                trie[node][c - 'a'] = ++total_nodes;
            }
            node = trie[node][c - 'a'];
        }   
        ends_at[node] = true;
    }
    
    bool search(string word) {
        int n = word.size();
        auto rec = [&](auto & rec,  int i, int node) -> bool {
            if (i == n) return ends_at[node];
            char c = word[i];
            if (c == '.') {
                for (int j = 0; j < 26; j++) {
                    if (trie[node][j] == 0) continue;
                    if (rec(rec, i + 1, trie[node][j])) return true;
                }
                return false;
            } 
            if (trie[node][c - 'a'] == 0) return false;
            return rec(rec, i + 1, trie[node][c - 'a']);
        };
        return rec(rec, 0, 0);
    }
};
