class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string sol = "";
        string first = strs[0];
        for( int i = 0 ; i < first.length(); i++){
            int x = 1;
            for (int j = 1; j < strs.size(); j++){
                string next = strs[j];
                if(first[i] != next[i])
                    x = 0;
            }
            if (x == 1)
                sol += first[i];
            else
                break;
        }
         return (sol); }
};