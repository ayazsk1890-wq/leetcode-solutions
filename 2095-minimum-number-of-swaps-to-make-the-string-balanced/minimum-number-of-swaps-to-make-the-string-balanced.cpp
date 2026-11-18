class Solution {
public:
    int minSwaps(string s) {
        if(s.length() % 2 != 0) return 0;
        stack<char>st;
        for(char ch : s){
            if(ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        int a = 0, b = 0;
        while(!st.empty()){
            if(st.top() == ']') b++;
            else a++;
            st.pop();
        }
        int ans = (a+1)/2 + (b+1)/2;
        return ans/2;
    }
};