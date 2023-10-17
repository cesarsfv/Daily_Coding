#include <iostream>
#include <cstdint>

class Node {
public:
    int value;
    Node* both;

    Node(int val) : value(val), both(nullptr) {}
};

Node* XOR(Node* a, Node* b) {
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}

class XORLinkedList {
private:
    Node* head;

public:
    XORLinkedList() : head(nullptr) {}

    void add(int element) {
        Node* new_node = new Node(element);
        new_node->both = XOR(head, nullptr);

        if (head != nullptr) {
            head->both = XOR(new_node, XOR(head->both, nullptr));
        }

        head = new_node;
    }

    Node* get(int index) {
        Node* current = head;
        Node* prev = nullptr;

        for (int i = 0; i < index; i++) {
            if (current == nullptr) return nullptr;

            Node* next = XOR(prev, current->both);
            prev = current;
            current = next;
        }

        return current;
    }
};

int main() {
    XORLinkedList xor_linked_list;
    xor_linked_list.add(1);
    xor_linked_list.add(2);
    xor_linked_list.add(3);

    Node* node = xor_linked_list.get(1);
    if (node != nullptr) {
        std::cout << node->value << std::endl;  // Deve imprimir 2
    }

    return 0;
}
