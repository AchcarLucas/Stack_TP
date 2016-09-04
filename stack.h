#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <typename T>
struct Stack{
    unsigned int head;
    unsigned int max;
    T *stack;

    Stack(unsigned int);
    ~Stack();
    void push(T);
    T pop();
    unsigned int getIndexHead();
    T getHead();
    T getIndex(unsigned int);
    unsigned int getSize();
    bool isFull();
    bool isEmpty();
};

template <typename T>
Stack<T>::Stack(unsigned int size){
    max = size;
    head = 0;
    stack = new T[size];
}

template <typename T>
Stack<T>::~Stack(){
    if(stack != NULL)
        delete stack;
}

template <typename T>
void Stack<T>::push(T value){
    if(!isFull()){
        stack[head++] = value;
    }
}

template <typename T>
T Stack<T>::pop(){
    if(!isEmpty()){
        return stack[--head];
    }
    return -1;
}

template <typename T>
unsigned int Stack<T>::getIndexHead(){
    return head;
}

template <typename T>
T Stack<T>::getHead(){
    if(!isEmpty())
        return stack[head - 1];
    return -1;
}

template <typename T>
T Stack<T>::getIndex(unsigned int index){
    if(index >= 0 && index < max)
        return stack[index];
    return -1;
}

template <typename T>
unsigned int Stack<T>::getSize(){
    return max;
}

template <typename T>
bool Stack<T>::isFull(){
    return head == max;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return head == 0;
}

#endif // STACK_H_INCLUDED
