#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

struct SinglyLinkedList {
	SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
		this->head = nullptr;
        this->tail = nullptr;
    }

	void insert_node(int node_data);
};

void SinglyLinkedList::insert_node(int node_data)
{
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		} else {
			this->tail->next = node;
		}

		this->tail = node;
}



void print_singly_linked_list(SinglyLinkedListNode* node,char sep=' ') {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
    cout << '\n';
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}



SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head_list1,SinglyLinkedListNode* head_list2){
    SinglyLinkedList* newList = new SinglyLinkedList();
    while (head_list1 != NULL && head_list2 != NULL){
        if (head_list1->data <= head_list2->data){
            newList->insert_node(head_list1->data);
            head_list1 = head_list1->next;
        }
        else{
            newList->insert_node(head_list2->data);
            head_list2 = head_list2->next;
        }
    }

    while (head_list1 != NULL){
        newList->insert_node(head_list1->data);
        head_list1 = head_list1->next;
    }

    while (head_list2 != NULL){
        newList->insert_node(head_list2->data);
        head_list2 = head_list2->next;
    }

    return newList->head;
}


int main (){
    if (fopen("test.inp", "r")){
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    }
    cin.tie(0); std::ios::sync_with_stdio(false);
    
    int tests;
    cin >> tests;
    
    
    for (int t = 0; t < tests; t++){
		int llist1_num, llist2_num;
		cin >> llist1_num >> llist2_num;
		
		SinglyLinkedList* llist1 = new SinglyLinkedList();
		
		
		for (int i = 0; i < llist1_num; i++){
			int llist1_item;
			cin >> llist1_item;
			
			llist1->insert_node(llist1_item);
		}
		
		SinglyLinkedList* llist2 = new SinglyLinkedList();

		
		for (int i = 0; i < llist2_num; i++){
			int llist2_item;
			cin >> llist2_item;
			
			llist2->insert_node(llist2_item);
		}
		
		SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);
		
		print_singly_linked_list(llist3);
		
		free_singly_linked_list(llist3);
		
		
	}
}
