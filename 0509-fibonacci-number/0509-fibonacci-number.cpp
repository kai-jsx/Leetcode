class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, c;
        switch (n) {
        case 0:
            c = a;
            break;
        case 1:
            c = b;
            break;
        default:
            for (int i = 2; i <= n; i++) {
                c = a + b;
                a = b;
                b = c;
            }
        }

        return (c);
    }
};