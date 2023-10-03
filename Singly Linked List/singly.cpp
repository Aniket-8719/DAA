#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    
    void deleteAtEnd() {
        if (head == nullptr) {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    std::cout << "Linked list after insertions at beginning: ";
    list.display();

    list.insertAtEnd(4);
    list.insertAtEnd(5);

    std::cout << "Linked list after insertions at end: ";
    list.display();

    list.deleteAtBeginning();
    list.deleteAtEnd();

    std::cout << "Linked list after deletions: ";
    list.display();

    return 0;
}
