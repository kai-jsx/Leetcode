class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size())
            return false;

        int c = 0, k = 0, f = 0;
        while (c < s.size()) {
            if(k == t.size())
                return false;

                
            if (t.find(s[c]) != string::npos) {
                if (s[c] == t[k]) {
                    c++;
                    k++;
                } else {
                    k++;
                    if(k == t.size()){
                        return false;
                    }
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};