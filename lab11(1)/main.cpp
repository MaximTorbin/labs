#include <iostream>
#include <algorithm>
bool haveOnly12345(int num)
{
    while (num>0)
    {
        if ( (num%10)>5 || (num%10)==0 )
            return 0;
        num/=10;
    }
    return 1;
}
bool have6or8(int num)
{
    while(num>0)
    {
        if( (num%10)==6 || (num%10)==8)
            return 1;
        num/=10;
    }
    return 0;
}
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val)
    {
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};

class CircularDoublyLinkedList
{
public:
    Node* head;

    CircularDoublyLinkedList()
    {
        head= new Node(0);
        head->next=head;
        head->prev=head;
    }

    void append(int val)// элемент вставляется в конец 
    {
        Node* newNode = new Node(val);
        Node* temp = head->prev; 
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }

    void del(Node* NodeDel)
    {
        if (NodeDel == head) 
            return;
        Node* prevNode=NodeDel->prev;
        Node* nextNode=NodeDel->next;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        delete NodeDel;
    }

    void doubleNode(Node* Nodefirst)
    {
        Node* NodeSecond=new Node(Nodefirst->data);
        NodeSecond->next=Nodefirst->next;
        Nodefirst->next=NodeSecond;
        NodeSecond->prev=Nodefirst;
    }

    void print() {
        Node* temp = head->next;
        if (temp==head)
        {
            std::cout<<"Пустая последовательность";
        }
        while (temp!=head)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    
    bool IsSorted()
    {
        int firstDigitPrev=0;
        int lastDigitPrev=0;
        bool T1=1; //Отсортировано по первой цифре
        bool T2=1; //Отсортировано по последней цифре
        Node* temp=head->next;
        while(temp!=head)
        {
            int current=temp->data;
            int first;
            int last=current%10;
            while (current>0)
            {
                first=current;
                current/=10;
            }
            if(firstDigitPrev>first)
                T1=0;
            else
                firstDigitPrev=first;
            if(lastDigitPrev>last)
                T2=0;
            else
                lastDigitPrev=last;
            if(T1==0&T2==0)
                return 0;
            temp=temp->next;
        }
        return 1;
    }


    void sortByNonGrowth()
    {
        if (head->next == head)
            return;
        Node* p1= head->next;
        while(p1!=head)
        {
            Node* p2=p1->next;
            while(p2!=head)
            {
                if ((p1->data)<(p2->data))
                    std::swap(p1->data,p2->data);
                p2=p2->next;
            }
            p1=p1->next;
        }
    }


    ~CircularDoublyLinkedList()
    {
        Node* curr=head->next;
        while (curr!=head)
        {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
    }
};

int main() {
    CircularDoublyLinkedList list;
    int num;

    std::cout << "Введите последовательность чисел (0 для завершения):" << std::endl;
    while (true)
    {
        std::cin >> num;
        if (num == 0)
            break;
        list.append(num);
    }

    if (list.IsSorted())
    {
        Node* temp = list.head->next;
        while (temp != list.head)
        {
            Node* next = temp->next;
            if (haveOnly12345(temp->data))
            {
                list.del(temp);
                temp = next;
            }
            else if(have6or8(temp->data))
            {
                list.doubleNode(temp);
                temp=next;
            }
            else
                temp=temp->next;
        }
    }
    else
        list.sortByNonGrowth();
    std::cout << "Результат:" << std::endl;
    list.print();

    return 0;
}