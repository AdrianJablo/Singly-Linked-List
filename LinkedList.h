#include <iostream>
#include <initializer_list>
#include <memory>
#include <functional>

template <typename T>
class LinkedList 
{
private:
    struct Node 
    {
        T value;
        std::unique_ptr<Node> next;

        Node(T value) : value(std::move(value)), next(nullptr) {}
    };

    std::unique_ptr<Node> head;
    Node* tail;
    size_t list_size;

public:
    LinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

    LinkedList(std::initializer_list<T> init_list) : LinkedList() 
    {
        for (const auto& value : init_list) 
        {
            push_back(value);
        }
    }

    LinkedList(LinkedList&& other) noexcept : head(std::move(other.head)), tail(other.tail), list_size(other.list_size)
    {
        other.tail = nullptr;
        other.list_size = 0;
    }

    LinkedList& operator=(LinkedList&& other) noexcept 
    {
        if (this != &other) 
        {
            head = std::move(other.head);
            tail = other.tail;
            list_size = other.list_size;
            other.tail = nullptr;
            other.list_size = 0;
        }
        return *this;
    }

    void push_front(const T& value) 
    {
        auto new_node = std::make_unique<Node>(value);
        if (!head) 
        {
            tail = new_node.get();
        }
        new_node->next = std::move(head);
        head = std::move(new_node);
        ++list_size;
    }

    void push_front(T&& value) 
    {
        auto new_node = std::make_unique<Node>(std::move(value));
        if (!head) 
        {
            tail = new_node.get();
        }
        new_node->next = std::move(head);
        head = std::move(new_node);
        ++list_size;
    }

    void push_back(const T& value) 
    {
        auto new_node = std::make_unique<Node>(value);
        Node* new_tail = new_node.get();
        if (tail) 
        {
            tail->next = std::move(new_node);
        }
        else 
        {
            head = std::move(new_node);
        }
        tail = new_tail;
        ++list_size;
    }

    void push_back(T&& value) 
    {
        auto new_node = std::make_unique<Node>(std::move(value));
        Node* new_tail = new_node.get();
        if (tail) 
        {
            tail->next = std::move(new_node);
        }
        else 
        {
            head = std::move(new_node);
        }
        tail = new_tail;
        ++list_size;
    }

    size_t size() const 
    {
        return list_size;
    }

    void pop_front() 
    {
        if (head) 
        {
            head = std::move(head->next);
            if (!head) 
            {
                tail = nullptr;
            }
            --list_size;
        }
    }

    void print() const 
    {
        Node* current = head.get();
        while (current) 
        {
            std::cout << current->value << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }

    LinkedList<T> split_when(std::function<bool(const T&)> predicate) 
    {
        LinkedList<T> result;
        Node* current = head.get();
        Node* prev = nullptr;

        while (current) 
        {
            if (predicate(current->value)) 
            {
                if (prev) 
                {
                    result.head = std::move(prev->next);
                    prev->next = nullptr;
                }
                else 
                {
                    result.head = std::move(head);
                    head = nullptr;
                }

                result.tail = tail;
                tail = prev;
                result.list_size = list_size - (prev ? 1 : 0);
                list_size -= result.list_size;
                break;
            }
            prev = current;
            current = current->next.get();
        }
        return result;
    }

    ~LinkedList() = default;

};