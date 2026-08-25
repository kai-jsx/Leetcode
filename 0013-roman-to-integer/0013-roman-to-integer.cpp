class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int n = s.length();
        int total = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(i < n-1 && mp[s[i]]<mp[s[i+1]])
                total -= mp[s[i]];
            else
                total += mp[s[i]];
        }

        cout << "The value for the roman numeral is:" << total << endl;
        return total;
    }
};