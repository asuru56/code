#include <iostream>

// Define the ListNode structure

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    
    while (current != nullptr) {
        ListNode* nextNode = current->next; // Save the next node
        current->next = prev; // Reverse the link
        
        // Move to the next nodes
        prev = current;
        current = nextNode;
    }
    
    return prev; // New head of the reversed list
}

// Function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    std::cout << "Original Linked List: ";
    printList(head);
    
    // Reverse the linked list
    head = reverseList(head);
    
    std::cout << "Reversed Linked List: ";
    printList(head);
    
    return 0;
}
