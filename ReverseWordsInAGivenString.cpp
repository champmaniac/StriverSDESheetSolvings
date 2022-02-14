class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int curr = S.size()-1;
        int count=0;
        string res="";
        for(int i=curr;i>=0;i--){
            if(S[i]=='.'){
                res=res+S.substr(i+1,count);
                res=res+'.';
                count=0;
            }
            else
                count++;
        }
        for(int i=0;S[i]!='.' && i<S.size();i++){
            res+=S[i];
        }
        return res;
    } 
};