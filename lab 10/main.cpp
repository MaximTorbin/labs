#include <iostream>
#include <vector>
#include <algorithm>

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head=nullptr;
    }

    void append(int val)
    {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void removeEvenStarting() {
        Node** current = &head;
        while (*current)
        {
            int del=(*current)->data;
            while(del>9)
                del/=10;
            if (del % 2 == 0)
            {
                Node* toDelete = *current;
                *current = (*current)->next;
                delete toDelete;
            } 
            else
            {
                current = &((*current)->next);
            }
        }
    }

    void duplicate() {
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->data);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
    }

    bool hasDuplicateDigits() {
        Node* temp = head;
        while (temp) {
            int num = abs(temp->data);
            bool haveDigit[10] = { false };
            while (num > 0) {
                int digit = num % 10;
                if (haveDigit[digit]) {
                    return true;
                }
                haveDigit[digit] = true;
                num /= 10;
            }
            temp = temp->next;
        }
        return false;
    }

    void sortByLastDigit()
    {
        std::vector<int> values;
        Node* temp = head;
        while (temp)
        {
            values.push_back(temp->data);
            temp = temp->next;
        }

        for(int i=0;i<values.size();i++)
        {
            for(int j=i+1;j<values.size();j++)
            {
                if (values[i]%10<values[j]%10)
                    std::swap(values[i],values[j]);
            }
  
            temp = head;
            for (int val : values)
            {
                temp->data = val;
                temp = temp->next;
            }
        }
    }

    ~LinkedList()
    {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int num;

    std::cout << "Введите последовательность чисел (0 для завершения):" << std::endl;
    while (true) {
        std::cin >> num;
        if (num == 0) break;
        list.append(num);
    }

    if (list.hasDuplicateDigits())
    {
        list.removeEvenStarting();
        list.duplicate();
    }
    else
    {
        list.sortByLastDigit();
    }

    std::cout << "Результат:" << std::endl;
    list.print();

    return 0;
}