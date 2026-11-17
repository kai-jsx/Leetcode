class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = (rows * cols) - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int midValue = matrix[mid / cols][mid % cols];
            if(target == midValue)
                return true;
            else if (target < midValue)
                high = mid - 1;
            else if (target > midValue)
                low = mid + 1;
        }
        return false;
    }
};