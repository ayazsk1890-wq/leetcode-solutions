class Solution {
private:
    bool isPalindrome(string s , int st , int e ){
        while(st < e){
            if (s[st++] != s[e--]){
            return false;
            }
        }
        return true;
    }
public:
    int maxPalindromes(string s, int k) {
        int count = 0 , end = 0;
        for (int i = 0 ; i < s.size() ; ++i){
            if ( i - k + 1 >= end && isPalindrome(s, i - k + 1, i)){
                count++;
                end = i + 1;
            }
            else if ( i - k >= end && isPalindrome(s, i - k, i)){
                count++;
                end = i + 1;
            }
        }
        return count;
    }
};