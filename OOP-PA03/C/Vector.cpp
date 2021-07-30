#include "Vector.h"
#include "Node.h"

using namespace std;

Vector::Vector(int n){
    capacity = n;
    len = 0;
    array = new Node[n];
}

Vector::~Vector(){
    delete[] array;
}

Vector::Vector(const Vector& other){
    capacity = other.capacity;
    len = other.len;
    array = new Node[capacity];
    for (int i = 0; i < len; i++){
        array[i] = other.array[i];
    }
}

Vector::Vector(Vector&& other){
    if(this != &other){
        capacity = other.capacity;
        len = other.len;
        array = other.array;
        other.array = nullptr;
        other.len = 0;
    }

}

Vector& Vector::operator=(const Vector& other){
    capacity = other.capacity;
    len = other.len;
    Node* oldArray = array;
    array = new Node[capacity];
    for (int i = 0; i < len; i++) {
        array[i] = other.array[i];
    }
    delete[] oldArray;
    return *this;
}

Vector& Vector::operator=(Vector&& other){
    if (this != &other) {
        capacity = other.capacity;
        len = other.len;
        Node* oldArray = array;
        array = other.array;
        other.array = nullptr;
        delete[] oldArray;
        other.len = 0;
    }
    return *this;
}

Node& Vector::operator[](int pos){
    return array[pos];
}

void Vector::append(int value){
    array[len] = Node(value);
    len++;
}

void Vector::insert(int pos, int value){
    for (int i = len; i > pos; i--){
        array[i] = move(array[i - 1]);
    }
    array[pos] = move(Node(value));
    len++;
}

void Vector::swap(int pos1, int pos2){
    Node tmp(move(array[pos1]));
    array[pos1] = move(array[pos2]);
    array[pos2] = move(tmp);
}

void Vector::dilatation(){
    capacity *= 2;
    Node* newArray = new Node[capacity];
    for (int i = 0; i < len; i++) {
        newArray[i] = move(array[i]);
    }
    Node* oldArray = array;
    array = newArray;
    delete[] oldArray;
}

int Vector::getlen(){
    return len;
}