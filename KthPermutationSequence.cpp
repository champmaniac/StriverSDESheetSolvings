string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int> number;
    int fact=1;
    for(int i=1;i<n;i++)
    {
        fact=fact*i;
        number.push_back(i);
    }

    number.push_back(n);
    string ans="";
    k=k-1;
    while(true)
    {
        ans=ans+to_string(number[k/fact]);
        number.erase(number.begin()+k/fact);
        if(number.size()==0)
            break;
        k=k%fact;
        fact=fact/number.size();
    }
    return ans;
}
