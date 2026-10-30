#include <vector>
#include <string>

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> fb;
        fb.reserve(n); // 1. Pre-allocate memory to avoid vector reallocations

        int count3 = 0;
        int count5 = 0;

        for (int i = 1; i <= n; i++) {
            count3++;
            count5++;
            string s = "";

            // 2. Use counters instead of the expensive modulo (%) operator
            if (count3 == 3) {
                s += "Fizz";
                count3 = 0;
            }
            if (count5 == 5) {
                s += "Buzz";
                count5 = 0;
            }

            if (s.empty()) {
                s = to_string(i);
            }

            fb.push_back(s);
        }
        return fb;
    }
};