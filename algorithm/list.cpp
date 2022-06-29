
#include <iostream>
#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *CreateList(std::vector<int> &vec){
    ListNode head; // 虚拟节点
    ListNode *p = &head;
    for(auto &item : vec){
        p->next = new ListNode(item);
        p = p->next;
    }

    return head.next;
}

void Order(ListNode *head){
    while(head != nullptr){
        std::cout << head->val << "->";
        head = head->next;
    }
}

// 通过递归的方式,实现链表反序输出
void ReverseOrder(ListNode *head){
    if(head == nullptr){
        return;
    }

    ReverseOrder(head->next);
    std::cout << head->val << "->";
}

// 单链表反转[非递归]
ListNode *ReverseList(ListNode *head){
    if(head == nullptr){
        return head;
    }

    // 反转
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while(cur != nullptr){
        ListNode *next = cur->next;
        cur->next = pre;

        pre = cur;
        cur = next;
    }

    return pre;
}

// 单链表反转[递归]
ListNode *ReverseList2(ListNode *head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode *node = ReverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return node;
}


ListNode *CycleLink(ListNode *head){
    if(head == nullptr){
        return head;
    }
    // 后半部分的起始节点
    ListNode *post = nullptr;
    // 获取中间节点
    ListNode *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    post = slow->next;
    slow->next = nullptr; // 断开链表

    // 偶数 1 2 3 4
    // 奇数

    // 反转后半链表
    post = ReverseList(post);

    // 链表拼接
    ListNode dumpy(0);
    ListNode *node = &dumpy;
    while(head != nullptr && post != nullptr){
        node->next = head; 
        head = head->next;

        node = node->next;

        node->next = post;
        post = post->next;

        node = node->next;
    }

    while(head != nullptr){
        node->next = head; 
        head = head->next;

        node = node->next;
    }
    while(post != nullptr){
        node->next = post; 
        post = post->next;

        node = node->next;
    }

    return dumpy.next;
}



int main(){
    std::vector<int> vec{1,2,3,4,5,6};
    ListNode *head = CreateList(vec);

    // 正序输出
    Order(head);
    std::cout << std::endl;

    // 反序输出
    ReverseOrder(head);
    std::cout << std::endl;

    // 单链表反转
    head = ReverseList(head);
    Order(head);
    std::cout << std::endl;

    // 单链表反转
    head = ReverseList2(head);
    Order(head);
    std::cout << std::endl;

    // 回环
    // head = CycleLink(head);
    // Order(head);
    // std::cout << std::endl;


    return 0;
}
