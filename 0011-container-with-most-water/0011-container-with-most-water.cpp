class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right){
            int h1 = right - left;
            int h2 = min(height[left], height[right]);
            maxWater = max(maxWater, h1 * h2);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return (maxWater);
    }
};