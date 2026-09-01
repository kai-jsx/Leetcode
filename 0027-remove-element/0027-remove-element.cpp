class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; //the most important variable which will keep count of the variable except val and also help in arranging them in the loop
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};