class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int index = 0;
        for (int n : nums){
            int s = 0;
            while (n!=0){
                int r = n%10;
                s+=r;
                n/=10;
            }
            if(s==index)    return index;
            index++;
        }
        return -1;
    }
};