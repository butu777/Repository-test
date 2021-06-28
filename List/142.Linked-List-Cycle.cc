// 寻找循环链表
方法一：哈希表
ListNode *detectCycle(ListNode *head) {
    // unordered_set以hashtable组织元素
    unordered_set<ListNode *> visited;
    while (head != nullptr) {
        // 寻找是否有相同元素，若有则是循环链表入口
        if (visited.count(head)) {
            return head;
        }
        // insert返回a pair consisting of an iterator to the element and a bool
        visited.insert(head);
        head = head->next;
    }
    return nullptr;
}

方法二：快慢指针
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode *index1 = head;
            ListNode *index2 = slow;
            while (index1 != index2) {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }
    return nullptr;
}
