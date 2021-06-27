#ifndef GOOD_WORK_LINKEDLIST_H
#define GOOD_WORK_LINKEDLIST_H


#include "abstractions/Binary.h"
#include "node/Node.h"


template<typename Data>
class LinkedList : public Binary {
private:

    int length{0};
    Node<Data> *root;
    bool sorted{true};

    Node<Data> *getByIndex(int i);

    void init(Node<Data> *node);

    bool isOrdered(Node<Data> *checked);

    void addNext(Node<Data> *current, Node<Data> *added);

    void addPrev(Node<Data> *current, Node<Data> *added);

    Node<Data> *merge(Node<Data> *first_chain, Node<Data> *second_chain);

    void merge_sort();

    //Node<Data> *merge(Node<Data> *first_chain, Node<Data> *second_chain, int (*compare)(Data, Data));

    //void merge_sort(int (*compare)(Data, Data));

public:
    explicit LinkedList(Data data) : root(new Node<Data>(data)) {}

    LinkedList() = default;

    ~LinkedList();

    int size();

    void insert(Data data);

    void insert_sorted(Data data);

    void insert(Data data, int index);

    void remove(int index);

    Data get(int index);

    void sort();

    //void sort(int (*compare)(Data, Data));

    LinkedList<Data> &find(bool (*accept)(Data data));

    LinkedList<Data> &find(bool (*accept)(Data, Data), Data aboutData);

    void save_binary(std::ofstream &out) override;

    void load_binary(std::ifstream &in) override;



    class iterator
    {
    private:
        Node<Data>* current;
        Node<Data>* begin;
        bool end{true};
    public:
        iterator() = default;

        iterator(Node<Data>* node, bool end):
                current (node), begin(node){
            if(node == nullptr)
                this->end = true;
            else
                this->end = end;
        }

        iterator& operator=(Node<Data>* node)
        {
            this->current = node;
            return *this;
        }

        // Prefix ++ overload
        iterator& operator++()
        {
            if (current) {
                current = current->next;
                if(current == begin)
                    end = true;
                else
                    end = false;
            }
            return *this;
        }

        iterator operator++(int)
        {
            iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const iterator& iter)
        {
            return current != iter.current || end != iter.end;
        }

        Data operator*()
        {
            return current->data;
        }

    };

    iterator begin(){
        return iterator(root, false);
    }

    iterator end() {
        return iterator(root, true);
    }

};

#include "LinkedList.tpp"

#endif
