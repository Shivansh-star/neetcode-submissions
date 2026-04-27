/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* merging(ListNode* l1,ListNode* l2){

    ListNode* temp1=l1;
    ListNode* temp2=l2;

    ListNode dummy(0);
    ListNode* ans=&dummy;

    while(temp1!=nullptr && temp2!=nullptr){

        if(temp1->val > temp2->val){
            ans->next=temp2;
            temp2=temp2->next;
        }
        else{
            ans->next=temp1;
            temp1=temp1->next;
        }

        ans=ans->next;
    }

    if(temp1) ans->next=temp1;
    if(temp2) ans->next=temp2;

    return dummy.next;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)return nullptr;
        if(n == 1)return lists[0];
        if(n == 2)return merging(lists[0],lists[1]);
        ListNode* result = merging(lists[0],lists[1]);
        for(int i=2;i<n;i++){
            result = merging(result,lists[i]);
        }
        return result;
    }
};
