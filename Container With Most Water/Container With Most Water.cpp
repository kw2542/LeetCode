class Solution {
public:
    int maxArea(vector<int> &height) {
        int max = 0;
        int low = 0;
        int high = height.size() - 1;
        while (low < high) {
            int area = (high - low) * (height[low] > height[high] ? height[high] : height[low] );
            max = max > area ? max : area;
            if (height[low] < height[high]) ++low;
            else --high;
        }
        return max;
    }
};