class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1, x=n;
        while(n!=0){
            int r = n % 10;
            sum += r;
            product *= r;
            n /= 10;
        }
        if(x % (sum + product) == 0)    return true;
        else    return false;
    }
};