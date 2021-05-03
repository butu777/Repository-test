// 直接使用原来的链表移除节点操作
struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头节点
        while (head != NULL & head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头节点
        ListNode* cur = head;
        while (cur != NULL & cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};


// 设置一个虚拟头节点进行移除链表节点操作
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead-next = head;
        ListNode* cur = dummyHead;

        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return dummyHead-next;
    }
};
