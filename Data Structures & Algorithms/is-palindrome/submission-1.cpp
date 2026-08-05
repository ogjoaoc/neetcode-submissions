class Solution {
public:
    bool isPalindrome(string s) {
        string nS;
        for (char c : s) {
            if (c == ' ') continue;
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) nS += tolower(c);
            if (c >= '0' && c <= '9') nS += c;
        }
        int N = nS.size();
        cout << nS << '\n';
        for (int i = 0; i < N / 2; i++) {
            if (nS[i] != nS[N - 1 - i]) return false;
        }
        return true;
    }
};
