class Solution {
public:
    bool isPalindrome(int x) {
        long s = 0;
        int a = x;
        if (x < 0)
            return false;
        while(x!=0){
            int r = x%10;
            s = (s * 10) + r;
            x/=10;
        }
        return (s==a);

    }
};