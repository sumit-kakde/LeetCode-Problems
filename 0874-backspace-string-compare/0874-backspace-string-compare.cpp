class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0 && (s[i] == '#' || skipS > 0)) {
                if (s[i] == '#') {
                    skipS++;
                } else {
                    skipS--;
                }
                i--;
            }

            while (j >= 0 && (t[j] == '#' || skipT > 0)) {
                if (t[j] == '#') {
                    skipT++;
                } else {
                    skipT--;
                }
                j--;
            }

            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else if (i >= 0 || j >= 0) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};