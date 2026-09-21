class Solution {
public:
    bool isHappy(int n) {
        if ( n == 1) return true;
        int sum = 0;
        while (n>0){
          sum = sum + (n%10)*(n%10);
          n = n/10;
        }
        if (sum >1 && sum<10 && sum != 7) return false;
        return isHappy(sum);
    }
};