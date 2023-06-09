#include <iostream>
#include <algorithm>

// Struct untuk data pegawai
struct Employee {
    int id;
    std::string name;
    int age;
};

// Sorting berdasarkan ID
bool compareById(const Employee& emp1, const Employee& emp2) {
    return emp1.id < emp2.id;
}

// Searching berdasarkan nama
bool searchByName(const Employee& emp, const std::string& name) {
    return emp.name == name;
}

// Implementasi stack dengan array
const int MAX_SIZE = 100;
class Stack {
private:
    int top;
    int data[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack overflow!" << std::endl;
        } else {
            data[++top] = value;
        }
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        } else {
            return data[top--];
        }
    }
};

// Struct untuk node dalam linked list
struct Node {
    int data;
    Node* next;
};

// Implementasi linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Array
    int arr[] = {5, 2, 8, 1, 9};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    // Sorting array menggunakan algoritma bubble sort
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    std::cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Searching array
    int searchValue = 8;
    bool found = false;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == searchValue) {
            found = true;
            break;
        }
    }
    if (found) {
        std::cout << "Value " << searchValue << " found in the array." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the array." << std::endl;
    }

    // Struct
    Employee employees[3];
    employees[0] = {1, "John Doe", 30};
    employees[1] = {2, "Jane Smith", 25};
    employees[2] = {3, "Mike Johnson", 35};

    // Sorting array of struct by ID
    std::sort(employees, employees + 3, compareById);

    std::cout << "Sorted employees by ID:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "ID: " << employees[i].id << ", Name: " << employees[i].name << ", Age: " << employees[i].age << std::endl;
    }

    // Searching array of struct by name
    std::string searchName = "Jane Smith";
    found = false;
    for (int i = 0; i < 3; i++) {
        if (searchByName(employees[i], searchName)) {
            found = true;
            break;
        }
    }
    if (found) {
        std::cout << "Employee with name " << searchName << " found." << std::endl;
    } else {
        std::cout << "Employee with name " << searchName << " not found." << std::endl;
    }

    // Stack
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Popped values from the stack: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    // Linked List
    LinkedList linkedList;
    linkedList.insert(4);
    linkedList.insert(5);
    linkedList.insert(6);

    std::cout << "Linked List: ";
    linkedList.display();

    return 0;
}
