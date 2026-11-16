class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stack;
        for(char ch : s){
            stack.push(ch);
        }
        int i = 0;
        while(!stack.empty()){
            s[i++] = stack.top();
            stack.pop();
        }
    }
};