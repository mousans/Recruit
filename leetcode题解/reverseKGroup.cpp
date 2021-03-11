#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* head){
    ListNode *prev = nullptr;
    while(head!=nullptr){
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *res = new ListNode(-1);
    res->next = head;
    ListNode *cur = head;
    ListNode *lastTail = res;
    while(cur!=nullptr){
        int time = k;
        ListNode *curHead = cur;
        ListNode *curTail=nullptr;
        while(time>0 && cur!=nullptr){
            time--;
            curTail = cur;
            cur = cur->next;
        }
        if(time>0){
            break;
        }
        curTail->next = nullptr;
        lastTail->next = reverse(curHead);
        curHead->next = cur;
        lastTail = curHead;
    }
    return res->next;
}

int main(){

}