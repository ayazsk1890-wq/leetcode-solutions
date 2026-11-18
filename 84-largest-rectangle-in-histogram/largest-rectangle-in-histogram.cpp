class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // Pre-allocate a static or stack-allocated array to avoid std::stack (deque) heap overhead
        int st[100005]; 
        int top = -1;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            // Use 0 as a sentinel height at i == n to flush remaining elements in the stack
            int currHeight = (i == n) ? 0 : heights[i];

            while (top != -1 && currHeight < heights[st[top]]) {
                int h = heights[st[top--]];
                // If stack is empty, width spans from index 0 to i - 1 (width = i)
                int w = (top == -1) ? i : (i - st[top] - 1);
                maxArea = max(maxArea, h * w);
            }
            st[++top] = i;
        }

        return maxArea;
    }
};
