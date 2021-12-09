#include <iostream>
#include <list>
#include <stack>

using namespace std;

template<typename T = int>
class Stack{
private:
    list<T> LinkedList; //List container is a doubly linked list implementation
    int _size;
public:
    Stack(){_size = 0;} // Create an empty stack or

    Stack(T elem) {this->LinkedList.push_front(elem); _size = 1;}

    int GetSize(){return this->LinkedList.size();}

    bool isEmpty(){return _size == 0;}

    void Push(T);

    void Pop();

    T Top();

    void Print();
};

template<typename T>
void Stack<T>::Push(T elem){
    _size++;
    this->LinkedList.push_front(elem);
}

template<typename T>
void Stack<T>::Pop(){
    if (isEmpty()){
        cout << "\nList is empty";
        return;
    }
    else{
        T el = LinkedList.front();
        this->LinkedList.pop_front();
        _size--;
        cout << "\nRemoved " << el << " from stack";
    }
}

template<typename T>
T Stack<T>::Top(){
    if (isEmpty())
        throw runtime_error("Stack is empty");
    return LinkedList.front();
}

template<typename T>
void Stack<T>::Print(){
    typename list<T>::iterator it;
    for (it = LinkedList.begin(); it != LinkedList.end(); ++it){
        cout << (*it) << " ";
    }
}

int main()
{
    //In c++ it's already an implementation of a stack.

    stack<int> Stackk;
    Stackk.push(10);
    Stackk.top(); // first element
    Stackk.pop();

    Stack<int> s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Print();
    cout << "\n" << "Top element: " << s.Top();
    s.Pop();
    cout << "\nTop element after pop: " << s.Top();
    cout << "\n";
    s.Print();
    cout << "\nSize: " << s.GetSize();
    return 0;
}
