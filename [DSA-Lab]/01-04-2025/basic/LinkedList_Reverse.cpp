
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void insert_node(SinglyLinkedList* list, int x){
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(x);
    if (list->head == NULL){
        list->head = list->tail = newNode;
    }
    else{
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void reverse(SinglyLinkedListNode* current, SinglyLinkedList* list){
    if (current->next != NULL)
        reverse(current->next, list);
    insert_node(list, current->data);
}

void reverseLinkedList(SinglyLinkedList* &list){
    SinglyLinkedList* newList = new SinglyLinkedList();
    reverse(list->head, newList);
    list = newList;
}

void printLinkedList(SinglyLinkedList* list){
    SinglyLinkedListNode* current = list->head;
    while (current != NULL){
        cout << current->data << ' ';
        current = current->next;
    }
}

int main()
{
    if (fopen("test.inp", "r")){
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    }
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
 