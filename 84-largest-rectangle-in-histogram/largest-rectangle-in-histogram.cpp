// 1. Speed up LeetCode's hidden test-case parser before main() runs
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

// 2. Move the stack array to static/global BSS memory (zero per-call allocation)
static int st[100005];

class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        const int n = heights.size();
        const int* __restrict__ h_ptr = heights.data(); // Direct raw pointer access
        
        int top = -1;
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            const int curr = h_ptr[i];
            while (top >= 0 && curr < h_ptr[st[top]]) {
                const int height = h_ptr[st[top--]];
                const int width = (top < 0) ? i : (i - st[top] - 1);
                const int area = height * width;
                if (area > maxArea) maxArea = area;
            }
            st[++top] = i;
        }

        // Clean up remaining elements separately to avoid a ternary branch inside the hot loop
        while (top >= 0) {
            const int height = h_ptr[st[top--]];
            const int width = (top < 0) ? n : (n - st[top] - 1);
            const int area = height * width;
            if (area > maxArea) maxArea = area;
        }

        return maxArea;
    }
};

