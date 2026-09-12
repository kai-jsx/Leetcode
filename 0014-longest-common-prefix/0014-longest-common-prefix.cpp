class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // You don't even need a 'sol' variable!
        string first = strs[0];
        
        for (int i = 0; i < first.length(); i++) {
            
            for (int j = 1; j < strs.size(); j++) {
                // Check 1: Is the next word too short? (Prevents crash)
                // Check 2: Do the characters mismatch?
                if (i == strs[j].length() || first[i] != strs[j][i]) {
                    
                    // Slice 'first' from index 0, taking 'i' characters
                    return first.substr(0, i); 
                }
            }
        }
        
        // If we checked every letter and never broke out, 
        // the entire first word is the common prefix.
        return first; 
    }
};