#ifndef GOOD_WORK_NODE_H
#define GOOD_WORK_NODE_H

#include "../abstractions/Binary.h"

template<typename Data>
class LinkedList;

template<typename Data>
class Node : public Binary {
    friend class LinkedList<Data>;

private:
    Data data;
    Node *next{this};
    Node *prev{this};

public:
    explicit Node(Data data) : data(data) {};

    Node() = default;

    ~Node() = default;

    void save_binary(std::ofstream &out) override;

    void load_binary(std::ifstream &in) override;

    bool operator<(const Node &rhs) const;

    bool operator>(const Node &rhs) const;

    bool operator<=(const Node &rhs) const;

    bool operator>=(const Node &rhs) const;
};

template<class Data>
class Node<Data *> : public Binary {
    friend class LinkedList<Data *>;

private:
    Data *data{new Data()};
    Node<Data *> *next{this};
    Node<Data *> *prev{this};

public:
    explicit Node(Data *data) : data(data) {}

    Node() = default;

    ~Node() = default;

    void save_binary(std::ofstream &out) override;

    void load_binary(std::ifstream &in) override;

    bool operator<(const Node<Data *> &rhs) const;

    bool operator>(const Node<Data *> &rhs) const;

    bool operator<=(const Node<Data *> &rhs) const;

    bool operator>=(const Node<Data *> &rhs) const;
};

template<class Data>
class Node<Data &> : public Binary {
    friend class LinkedList<Data &>;

private:
    Data &data{*(new Data())};
    Node<Data &> *next{this};
    Node<Data &> *prev{this};

public:
    explicit Node(Data &data) : data(data) {};

    Node() = default;

    ~Node() = default;

    void save_binary(std::ofstream &out) override;

    void load_binary(std::ifstream &in) override;

    bool operator<(const Node<Data &> &rhs) const;

    bool operator>(const Node<Data &> &rhs) const;

    bool operator<=(const Node<Data &> &rhs) const;

    bool operator>=(const Node<Data &> &rhs) const;
};

#include "Node.tpp"

#endif