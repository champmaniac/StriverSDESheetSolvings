// Brute Force
// TC O(N*M) SC O(1)
int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node* firstHeadTemp = firstHead;
    while(firstHeadTemp!=NULL) // N
    {
        for(Node* secondHeadTemp=secondHead; secondHeadTemp!=NULL; secondHeadTemp=secondHeadTemp->next) // M
        {
            if(firstHeadTemp==secondHeadTemp)
                return firstHeadTemp->data;
        }
        firstHeadTemp=firstHeadTemp->next;
    }
    return -1;
}

// Better Approach using hashing
// TC O(N+M) SC O(N)
#include <unordered_set>
int findIntersection(Node *firstHead, Node *secondHead)
{
    Node* firstHeadTemp=firstHead;
    unordered_set<Node*> referenceSet;

    while(firstHeadTemp!=NULL){
        referenceSet.insert(firstHeadTemp);
        firstHeadTemp=firstHeadTemp->next;
    }

    Node* secondHeadTemp=secondHead;
    while(secondHeadTemp!=NULL)
    {
        if(referenceSet.find(secondHeadTemp)!=referenceSet.end())
            return secondHeadTemp->data;
        secondHeadTemp=secondHeadTemp->next;
    }
    return -1;
}