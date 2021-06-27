#include "LinkedList.h"
#include <cassert>

//Private part
template<typename Data>
void LinkedList<Data>::init(Node<Data> *node) {
    assert(node != nullptr);
    root = node;
    length = 1;
    sorted = true;
}

template<typename Data>
Node<Data> *LinkedList<Data>::getByIndex(int i) {
    if((i < 0 || i >= length))
        throw std::out_of_range(std::to_string(i));

    if (length / 2 >= i) {
        for (auto *current = root; i >= 0; i--, current = current->next)
            if (i == 0)
                return current;
    } else {
        for (auto *current = root; i <= length; i++, current = current->prev)
            if (i == length)
                return current;
    }
}

template<typename Data>
bool LinkedList<Data>::isOrdered(Node<Data> *checked) {
    return (checked == root && (*checked <= *(checked->next)))
           || (checked->next == root && (*(checked->prev) <= *checked))
           || ((*checked <= *(checked->next)) && (*checked >= *(checked->prev)));
}

template<typename Data>
void LinkedList<Data>::addNext(Node<Data> *current, Node<Data> *added) {
    assert(current != nullptr && added != nullptr);

    added->next = current->next;
    added->prev = current;
    current->next->prev = added;
    current->next = added;
    length++;
    sorted = isOrdered(added);
}

template<typename Data>
void LinkedList<Data>::addPrev(Node<Data> *current, Node<Data> *added) {
    assert(current != nullptr && added != nullptr);

    added->next = current;
    added->prev = current->prev;
    current->prev->next = added;
    current->prev = added;
    if (root == current)
        root = added;
    length++;
    sorted = isOrdered(added);
}

template<typename Data>
Node<Data> *LinkedList<Data>::merge(Node<Data> *first_chain, Node<Data> *second_chain) {
    Node<Data> *head;
    if (*first_chain <= *second_chain) {
        head = first_chain;
        first_chain = first_chain->next;
    } else {
        head = second_chain;
        second_chain = second_chain->next;
    }
    Node<Data> *current = head;
    while (first_chain != nullptr || second_chain != nullptr) {
        if (first_chain == nullptr || (second_chain != nullptr && *first_chain >= *second_chain)) {
            current->next = second_chain;
            second_chain = second_chain->next;
        } else {
            current->
                    next = first_chain;
            first_chain = first_chain->next;
        }
        current = current->next;
    }
    return
            head;
}

template<typename Data>
void LinkedList<Data>::merge_sort() {
    Node<Data> *hooks[32];
    for (auto &hook : hooks)
        hook = nullptr;
    Node<Data> *current = root;
    do {
        Node<Data> *temp = current;
        current = current->next;
        temp->next = nullptr;

        int hook = 0;
        while (hook < 32 && hooks[hook] != nullptr) {
            temp = merge(temp, hooks[hook]);
            hooks[hook] = nullptr;
            hook++;
        }
        hooks[hook] = temp;
    } while (current != root);
    current = nullptr;
    for (auto &hook : hooks) {
        if (hook != nullptr) {
            if (current == nullptr)
                current = hook;
            else
                current = merge(current, hook);
            hook = nullptr;
        }
    }
    for (auto iter = current; iter != nullptr; iter = iter->next) {
        if (iter->next != nullptr) {
            iter->next->prev = iter;
        } else {
            current->prev = iter;
            iter->next = current;
            break;
        }
    }
    for (auto &hook : hooks)
        delete hook;
    root = current;
}

/*template<typename Data>
Node<Data> *LinkedList<Data>::merge(Node<Data> *first_chain, Node<Data> *second_chain, int (*compare)(Data, Data)) {
    Node<Data> *head;
    if (compare(first_chain->data, second_chain->data) > 0) {
        head = first_chain;
        first_chain = first_chain->next;
    } else {
        head = second_chain;
        second_chain = second_chain->next;
    }
    Node<Data> *current = head;
    while (first_chain != nullptr || second_chain != nullptr) {
        if (first_chain == nullptr || (second_chain!= nullptr && compare(first_chain->data, second_chain->data) < 0)) {
            current->next = second_chain;
            second_chain = second_chain->next;
        } else {
            current->next = first_chain;
            first_chain = first_chain->next;
        }
        current = current->next;
    }
    return head;
}*/

/*template<typename Data>
void LinkedList<Data>::merge_sort(int (*compare)(Data, Data)) {
    Node<Data> *hooks[32];
    for (auto &hook : hooks)
        hook = nullptr;
    Node<Data> *current = root;
    do {
        Node<Data> *temp = current;
        current = current->next;
        temp->next = nullptr;

        int hook = 0;
        while (hook < 32 && hooks[hook] != nullptr) {
            temp = merge(temp, hooks[hook], compare);
            hooks[hook] = nullptr;
            hook++;
        }
        hooks[hook] = temp;
    } while (current != root);
    current = nullptr;
    for (auto &hook : hooks) {
        if (hook != nullptr) {
            if (current == nullptr)
                current = hook;
            else
                current = merge(current, hook, compare);
            hook = nullptr;
        }
    }
    for (auto iter = current; iter != nullptr; iter = iter->next) {
        if (iter->next != nullptr) {
            iter->next->prev = iter;
        } else {
            current->prev = iter;
            iter->next = current;
            break;
        }
    }
    for (auto &hook : hooks)
        delete hook;
    root = current;
}*/

/*template<typename Data>
void LinkedList<Data>::sort(int (*compare)(Data, Data)) {
    merge_sort(compare);
}*/

//Public part
template<typename Data>
LinkedList<Data>::~LinkedList() {
    Node<Data> *currentPtr = root;
    Node<Data> *tempPtr;
    if (root != nullptr)
        root->prev->next = nullptr;

    while (currentPtr) {
        tempPtr = currentPtr;
        currentPtr = currentPtr->next;
        delete tempPtr;
    }

}

template<typename Data>
int LinkedList<Data>::size() {
    return length;
}

template<typename Data>
void LinkedList<Data>::insert(Data data) {
    auto added = new Node<Data>(data);
    if (root == nullptr)
        init(added);
    else
        addNext(root->prev, added);
}

template<typename Data>
void LinkedList<Data>::insert(Data data, int index) {
    if (length == 0)
        init(new Node<Data>(data));
    else
        addPrev(getByIndex(index), new Node<Data>(data));
}

template<typename Data>
void LinkedList<Data>::insert_sorted(Data data) {
    auto added = new Node<Data>(data);
    if (root == nullptr) {
        init(added);
    } else {
        if (!sorted)
            sort();
        if (*added < *root) {
            addPrev(root, added);
        } else {
            auto current = root;
            do {
                if (*added >= *current && *added <= *(current->next)) {
                    addNext(current, added);
                    break;
                }
                current = current->next;
            } while (current != root);
        }
    }
}

template<typename Data>
void LinkedList<Data>::remove(int index) {
    auto removed = getByIndex(index);
    if (removed == root) {
        if (length == 1)
            root = nullptr;
        else
            root = root->next;
    }
    removed->prev->next = removed->next;
    removed->next->prev = removed->prev;
    delete removed;
    length--;
}

template<typename Data>
Data LinkedList<Data>::get(int index) {
    return getByIndex(index)->data;
}

template<typename Data>
void LinkedList<Data>::sort() {
    merge_sort();
    sorted = true;
}

template<typename Data>
LinkedList<Data> &LinkedList<Data>::find(bool (*accept)(const Data, const Data), Data aboutData) {
    auto result = new LinkedList();
    if (!root) return *result;
    auto current = root;
    do {
        if (accept(current->data, aboutData))
            result->insert(current->data);
        current = current->next;
    } while (current != root);
    return *result;
}

template<typename Data>
LinkedList<Data> &LinkedList<Data>::find(bool (*accept)(Data)) {
    auto result = new LinkedList();
    auto current = root;
    do {
        if (accept(current->data))
            result->insert(current->data);
        current = current->next;
    } while (current != root);
    return *result;
}

template<typename Data>
void LinkedList<Data>::save_binary(std::ofstream &out) {
    out.write((char *) &length, sizeof(length));
    auto current = root;
    for (int i = 0; i < length; i++, current = current->next) {
        current->save_binary(out);
    }
}

template<typename Data>
void LinkedList<Data>::load_binary(std::ifstream &in) {
    int _length = 0;
    in.read((char *) &_length, sizeof(_length));
    //free list?
    for (int i = 0; i < _length; i++) {
        auto *tmp = new Node<Data>();
        tmp->load_binary(in);
        if (root == nullptr)
            init(tmp);
        else
            addNext(root->prev, tmp);
    }
}
