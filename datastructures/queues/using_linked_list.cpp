#include <iostream>
#include <exception>
#include <string>

template<typename U>
class MyQueue {
public:
  MyQueue() {
    first = new Node<U>;
    last = first;
    size++;
  }
  MyQueue(U val) {
    first = new Node<U>(val);
    last = first;
    size++;
  }
  ~MyQueue() {
    Node<U>* curr = first;

    while (curr != nullptr) {
      Node<U>* next = curr->next;
      delete curr;
      curr = next;
    }
  }


  void enqueue(U val) {
    last->next = new Node<U>(val);
    last = last->next;
    size++;
  }
  // void prepend(int val) {
  //   Node<U>* pre = new Node(val);
  //   pre->next = first;
  //   first = pre;
  //   size++;
  // }

  void dequeue() {
    Node<U>* tmp = first;
    first = first->next;
    delete tmp;

    size--;
  }
  U peek() {
    return first->value;
  }


  void print() {
    Node<U>* curr = first;

    std::cout << "[";
    while (curr != nullptr) {
      std::cout << curr->value;

      if (curr != last) std::cout << ",";
      curr = curr->next;
    }

    std::cout << "]" << std::endl;
  }

private:
  template<typename T>
  class Node {
  public:
    Node() {
      value = 0;
      next = nullptr;
    }
    Node(T val) {
      value = val;
      next = nullptr;
    }

    T value;
    Node<T>* next;
  };

  Node<U>* first;
  Node<U>* last;
  int size = 0;
};

int main() {
  MyQueue<std::string> queue("Frank");
  queue.print();

  queue.enqueue("Julie");
  queue.print();

  queue.enqueue("Ted");
  queue.print();

  std::cout << queue.peek() << std::endl;

  queue.dequeue();
  queue.print();
}
