#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    ~Node() {}

    friend std::ostream& operator<<(std::ostream& stream, const Node& node);
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() 
    { 
        dispose(); 
    }
    int Length()
    {
        int count = 0;
        Node* current = head;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }

    void PushHead(int data)
    {
        Node* newHead = new Node(data);
        InsertNode(0, newHead);
    }

    void Insert(int index, int data)
    {
        Node* newHead = new Node(data);
        InsertNode(index, newHead);
    }

    void PushTail(int data)
    {
        Node* newHead = new Node(data);
        InsertNode(Length(), newHead);
    }

    int PopHead()
    {
        return PopData(ExtractNode(0));
    }

    int Extract(int index)
    {
        return PopData(ExtractNode(index));
    }

    int PopTail()
    {
        return PopData(ExtractNode(Length() - 1));
    }

    int Data(int index)
    {
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; ++i)
        {
            current = current->next;
        }
        if (current != nullptr) {
            return current->data;
        }
        else {
            return 0;
        }

    }

    void swap(int ia, int ib)
    {
        if (ia == ib)
        {
            return;
        }
        if (ia > ib)
        {
            return swap(ia, ib);
        }
        Node* nodeA = ExtractNode(ia);
        Node* nodeB = ExtractNode(ib - 1);
        if (nodeA == nullptr || nodeB == nullptr)
        {
            return;
        }
        InsertNode(ia, nodeB);
        InsertNode(ib, nodeA);
    }

    void sort()
    {
        for (int i = Length() - 1; i >= 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (Data(j) > Data(j + 1))
                {
                    swap(j, j + 1);
                }
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
    {
        Node* current = list.head;
        while (current != nullptr)
        {
            stream << *current << " ";
            current = current->next;
        }
        return stream;
    }

private:
    void dispose()
    {
        while (!IsEmpty())
        {
            PopHead();
        }
    }

    int PopData(Node* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int res = node->data;
        delete node;
        return res;
    }

    Node* head;

    void InsertNode(int index, Node* node)
    {
        if (index <= 0 || head == nullptr)
        {
            node->next = head;
            head = node;
        }
        else
        {
            Node* current = head;
            for (int i = 0; i < index - 1 && current->next != nullptr; ++i)
            {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }

    Node* ExtractNode(int index)
    {
        if (index < 0 || index >= Length())
        {
            return nullptr;
        }
        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            return temp;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; ++i)
        {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        return temp;
    }

    bool IndexValid(int index) const
    {
        Node* current = head;
        for (int i = 0; i < index && current; ++i)
        {
            current = current->next;
        }
        return current != nullptr;
    }
};

std::ostream& operator<<(std::ostream& stream, const Node& node)
{
    stream << node.data;
    return stream;
}

int main(int argc, char* argv[])
{
    LinkedList list;
    std::cout << list << std::endl;
    list.PushHead(1);
    std::cout << list << std::endl;
    list.PushTail(3);
    std::cout << list << std::endl;
    list.Insert(1, 2);
    std::cout << list << std::endl;
    list.Insert(3, 4);
    std::cout << list << std::endl << std::endl;
    std::cout << list << std::endl;
    std::cout << list.PopHead() << " ";
    std::cout << list.Extract(1) << " ";
    std::cout << list.PopTail() << " ";
    std::cout << list.Extract(0) << std::endl;
    std::cout << list << std::endl << std::endl;

    list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
    list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
    std::cout << list << std::endl;
    list.sort();
    std::cout << list << std::endl;
    return EXIT_SUCCESS;
}