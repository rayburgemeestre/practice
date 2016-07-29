/*
   LinkedList
   Node        Node        Node    
   next ---> next ---> next ---> nullptr
   nullptr <--prev <--- prev <--- prev
*/
#include <iostream>

struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
};

class LinkedList {
    public:
        Node *head = nullptr;
        Node *tail = nullptr;

        ~LinkedList() {
            for (Node *n = head; n;) {
                Node *next = n->next;
                remove(n);
                n = next;
            }
        }

        bool insert(Node *new_node, Node *before_node = nullptr) {
            Node *previous = nullptr;
            for (Node *n = head; ; n = n->next) {
                if (before_node == n) {
                    if (previous) {
                        previous->next = new_node;
                        new_node->prev = previous;
                    } else {
                        head = new_node;
                        if (!tail) {
                            tail = head;
                        }
                    }
                    new_node->next = n;
                    if (before_node) {
                        before_node->prev = new_node;
                    } else {
                        tail = new_node;
                    }
                    return true;
                }
                previous = n;
                if (n == nullptr) {
                    break;
                }
            }
            return false;
        }

        bool remove(Node *node_to_remove) {
            Node *previous = nullptr;
            for (Node *n = head; n; n = n->next) {
                if (n == node_to_remove) {
                    if (previous) {
                        previous->next = (n) ? n->next : nullptr;
                    } else {
                        head = n->next;
                    }
                    if (n->next) {
                        n->next->prev = previous;
                    } else {
                        tail = previous;
                    }
                    return true;
                }
                previous = n;
            }
            return false;
        }

};

int main()
{
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    LinkedList ll;

    ll.insert(node1 /*,  nullptr */);
    ll.insert(node2, node1);
    ll.insert(node3, node1);

    for (Node *n = ll.head; n; n = n->next) {
        std::cout << "got node\n";
    }
    for (Node *n = ll.tail; n; n = n->prev) {
        std::cout << "got node 2\n";
    }

    ll.remove(node2);

    for (Node *n = ll.head; n; n = n->next) {
        std::cout << "got node\n";
    }
    for (Node *n = ll.tail; n; n = n->prev) {
        std::cout << "got node 2\n";
    }

}

