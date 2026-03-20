class Solution {
public:
    int trap(vector<int>& height) {

        int left, total, leftMax, rightMax = 0;
        int right = height.size()-1;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] < leftMax) {
                    total += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
                left++;
            } else {
                if (height[right] < rightMax) {
                    total+= rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
                right--;
            }
        }
        return total;
        
    }
};