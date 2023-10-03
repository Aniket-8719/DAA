#include <iostream>
using namespace std;
struct Node {
int data;
Node* prev;
Node* next;
};
class DoublyLinkedList {
public:
DoublyLinkedList() {
head = nullptr;
tail = nullptr;
}
void insert_at_beginning(int data) {
Node* new_node = new Node();
new_node->data = data;
new_node->prev = nullptr;
new_node->next = head;
if (head == nullptr) {
tail = new_node;
} else {
head->prev = new_node;
}
head = new_node;

}
void insert_at_end(int data) {
Node* new_node = new Node();
new_node->data = data;
new_node->prev = tail;
new_node->next = nullptr;
if (tail == nullptr) {
head = new_node;
} else {
tail->next = new_node;
}
tail = new_node;
}
void delete_at_beginning() {
if (head == nullptr) {
return;
}
Node* temp = head;
head = head->next;
if (head == nullptr) {
tail = nullptr;
} else {
head->prev = nullptr;
}
delete temp;
}

void delete_at_end() {
if (tail == nullptr) {
return;
}
Node* temp = tail;
tail = tail->prev;
if (tail == nullptr) {
head = nullptr;
} else {
tail->next = nullptr;
}
delete temp;
}
void print_list() {
Node* current_node = head;
while (current_node != nullptr) {
cout << current_node->data << " ";
current_node = current_node->next;
}
cout << endl;
}
private:
Node* head;
Node* tail;
};
int main() {
DoublyLinkedList doubly_linked_list;

doubly_linked_list.insert_at_beginning(3);
doubly_linked_list.insert_at_end(5);
doubly_linked_list.insert_at_end(7);
doubly_linked_list.insert_at_end(9);
cout << "Doubly linked list:" << endl;
doubly_linked_list.print_list();
doubly_linked_list.insert_at_beginning(1);
cout << "Doubly linked list after insertion at the beginning:" << endl;
doubly_linked_list.print_list();
doubly_linked_list.insert_at_end(5);
cout << "Doubly linked list after insertion at the end:" << endl;
doubly_linked_list.print_list();
doubly_linked_list.delete_at_beginning();
cout << "Doubly linked list after deletion at the beginning:" << endl;
doubly_linked_list.print_list();
doubly_linked_list.delete_at_end();
cout << "Doubly linked list after deletion at the end:" << endl;
doubly_linked_list.print_list();
cout<<"Aniket Savita"<<" 21BCS8719";
return 0;
}