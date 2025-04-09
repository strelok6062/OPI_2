#include <iostream>

typedef short T;

struct Node {
    T Data;
    Node* Next;
};

Node* CreateNode(T value) {
    Node* newNode = new Node;
    newNode->Data = value;
    newNode->Next = nullptr;
    return newNode;
}

void AddToStart(Node*& head, T value) {
    Node* newNode = CreateNode(value);
    newNode->Next = head;
    head = newNode;
}

void PrintList(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->Data << " ";
        temp = temp->Next;
    }
    std::cout << std::endl;
}

T SumEvenElements(Node* head) {
    T sum = 0;
    Node* temp = head;
    while (temp) {
        if (temp->Data % 2 == 0) {
            sum += temp->Data;
        }
        temp = temp->Next;
    }
    return sum;
}

void DeleteList(Node*& head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->Next;
        delete temp;
    }
}

int main() {
    Node* Head = nullptr;

    T values[] = { 6, -11, 15, 21, 8, -14, 18, 22, 11, 13, 20, 24, -26, 28, 30, 32, 33 };
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        AddToStart(Head, values[i]);
    }

    std::cout << "List: ";
    PrintList(Head);

    T sumEven = SumEvenElements(Head);
    std::cout << "Sum of even elements: " << sumEven << std::endl;

    DeleteList(Head);
    return 0;
}
