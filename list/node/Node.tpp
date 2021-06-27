#include "Node.h"

//Primitive and references
template<typename Data>
bool Node<Data>::operator<(const Node &rhs) const {
    return data < rhs.data;
}

template<typename Data>
bool Node<Data>::operator>(const Node &rhs) const {
    return data > rhs.data;
}

template<typename Data>
bool Node<Data>::operator<=(const Node &rhs) const {
    return data <= rhs.data;
}

template<typename Data>
bool Node<Data>::operator>=(const Node &rhs) const {
    return data >= rhs.data;
}

template<typename Data>
void Node<Data>::load_binary(std::ifstream &in) {
    in.read((char *) &data, sizeof(data));
}

template<typename Data>
void Node<Data>::save_binary(std::ofstream &out) {
    out.write((char *) &data, sizeof(data));
}

template<class Data>
bool Node<Data &>::operator<(const Node<Data &> &rhs) const {
    return data < rhs.data;
}

template<class Data>
bool Node<Data &>::operator>(const Node<Data &> &rhs) const {
    return data > rhs.data;
}

template<class Data>
bool Node<Data &>::operator<=(const Node<Data &> &rhs) const {
    return data <= rhs.data;
}

template<class Data>
bool Node<Data &>::operator>=(const Node<Data &> &rhs) const {
    return data >= rhs.data;
}

template<typename Data>
void Node<Data &>::load_binary(std::ifstream &in) {
    if (std::is_base_of<Binary, Data>::value) {
        try {
            auto binary = reinterpret_cast<Binary *>( &data );
            binary->load_binary(in);
        } catch (...) {

        }
    } else {
        in.read((char *) &data, sizeof(data));

    }
}

template<typename Data>
void Node<Data &>::save_binary(std::ofstream &out) {
    if (std::is_base_of<Binary, Data>::value) {
        try {
            auto binary = reinterpret_cast<Binary *>( &data );
            binary->save_binary(out);
        } catch (...) {

        }
    } else {
        out.write((char *) &data, sizeof(data));
    }
}

//Pointer
template<class Data>
bool Node<Data *>::operator<(const Node<Data *> &rhs) const {
    return *data < *(rhs.data);
}

template<class Data>
bool Node<Data *>::operator>(const Node<Data *> &rhs) const {
    return *data > *(rhs.data);
}

template<class Data>
bool Node<Data *>::operator<=(const Node<Data *> &rhs) const {
    return *data <= *(rhs.data);
}

template<class Data>
bool Node<Data *>::operator>=(const Node<Data *> &rhs) const {
    return *data >= *(rhs.data);
}

template<typename Data>
void Node<Data *>::load_binary(std::ifstream &in) {
    if (std::is_base_of<Binary, Data>::value) {
        try {
            auto binary = reinterpret_cast<Binary *>( data );
            binary->load_binary(in);
        } catch (...) {

        }
    } else {
        in.read((char *) &data, sizeof(data));

    }
}

template<typename Data>
void Node<Data *>::save_binary(std::ofstream &out) {
    if (std::is_base_of<Binary, Data>::value) {
        try {
            auto binary = reinterpret_cast<Binary *>( data );
            binary->save_binary(out);
        } catch (...) {
        }
    } else {
        out.write((char *) &data, sizeof(data));
    }
}