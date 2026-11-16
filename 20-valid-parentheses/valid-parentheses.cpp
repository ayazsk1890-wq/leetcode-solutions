class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                S.push(ch);
            }
            else{
                if(!S.empty()){
                    char top = S.top();
                    if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')){
                        S.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return S.empty();
    }
};