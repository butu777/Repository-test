// 链表常见操作

class Solution {
public:
    // 定义链表节点
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val):val(val), next(nullptr) {}
    };

    // 判断节点索引的合理性0~size-1
    bool validIndex(int index) {
        if (index >= 0 && index < _size) {
            return true;
        }
        return false;
    }

    // 通过索引获取链表值
    int getVal(int index) {
        if (validIndex(index)) {
            ListNode* cur = _dummyNode;
            while (index--) {
                cur = cur->next;
            }
        } else {
            return -1;
        }
        return cur->val;
    }

    // 头插法
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyNode->next;
        _dummyNode->next = newNode;
        _size++;
    }

    // 尾插法
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyNode;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 通过索引插入节点
    void addAtIndext(int index, int val) {
        if (validIndex(index)) {
            ListNode* newNode = new ListNode(val);
            ListNode* cur = _dummyNode;
            while (index--) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            ++_size;
        } else if (index < 0) {
            addAtHead(val);
            ++_size;
        } else if (index == _size) {
            addAtTail(val);
            ++_size;
        }
    }

    // 通过索引删除元素
    void deleteAtIndex(int index) {
        if (validIndex(index)) {
            ListNode* cur = _dummyHead;
            ListNode* tmp;
            while (index--) {
                cur = cur->next;
            }
            tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            _size--;
        }
    }
private:
    ListNode* _dummyNode;
    int _size;

};
