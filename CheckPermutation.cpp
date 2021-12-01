// Brute Force
// TC O(N*logN) SC O(1)
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int n1 = str1.length();
    int n2 = str2.length();

    if(n1!=n2)
        return false;

    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());

    for(int i=0;i<n1;i++)
    {
        if(str1[i]!=str2[i])
            return false;
    }
    return true;
}

// Optimized using hashing
// TC O(N) SC O(No of characters)
#define NO_OF_CHARS 256
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int n1 = str1.length();
    int n2 = str2.length();
    int hash[NO_OF_CHARS] ={0};
    int i;
    if(n1!=n2)
        return false;

    for(i=0;i<n1;i++)
    {
        hash[str1[i]]++;
        hash[str2[i]]--;
    }

    for(int i=0;i<NO_OF_CHARS;i++)
    {
        if(hash[i])
            return false;
    }
    return true;
}