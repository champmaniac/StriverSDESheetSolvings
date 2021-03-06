// Brute force giving the optimal answer using stack here
// TC O(N) SC O(N)
bool isValidParenthesis(string s)
{
    stack<char>st;
    for(auto it:s)
    {
        if(it=='(' || it=='{' || it=='[') st.push(it);
        else{

            if(st.size()==0) return false;
            char ch = st.top();
            st.pop();
            if((it==')' && ch=='(') || (it=='}' && ch=='{') || (it==']' && ch=='['))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}