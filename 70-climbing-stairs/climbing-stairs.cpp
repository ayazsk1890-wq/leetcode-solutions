class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int prev1 = 1 , prev2 = 0 , current = 0;
        for(int i = 0 ; i < n ; i++){
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};