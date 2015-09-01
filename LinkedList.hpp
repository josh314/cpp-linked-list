#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <iostream>
//TODO: encapsulate ListNode within List? 

/************* class ListNode *****************
 * Used by class List (defined below)         *
 **********************************************/  
template<typename T>
class ListNode {
public:
  ListNode(): next_(NULL), data_(NULL) {} 
  inline void set_data(T& data) {data_ = &data;}
  inline T* get_data() {return data_;}
  inline void set_next(ListNode *next) {next_ = next;}
  inline ListNode *get_next() {return next_;}
  inline void print() { std::cout << *data_;}
  inline void insert_after(ListNode *new_node) {
    new_node->next_ = next_;
    next_ = new_node;
  }
private:
  ListNode *next_;
  T *data_;
};

/********** class List ************************
 * Singly linked list. Does not own data that *
 * is stored in its ListNodes                 *
 **********************************************/
template<typename T>
class List {
public:
  List(): head_(NULL) {}
  ~List();
  ListNode<T> *new_item_back(T& item);
  ListNode<T> *new_item_front(T& item);
  ListNode<T> *insert_after(ListNode<T> *node, T& item);
  void print();
private:
  ListNode<T> *head_;
};

/*** Implementation of List is below **********/
template<typename T>
List<T>::~List() {
  while(head_) {
    ListNode<T> *next = head_->get_next();
    delete head_;
    head_ = next;
  }
}

template<typename T>
ListNode<T> *List<T>::new_item_back(T& item) {
  auto *new_node = new ListNode<T>();
  new_node->set_data(item);
  new_node->set_next(NULL);

  if(!head_) {
    head_ = new_node;
    head_->set_data(item);
    return new_node;
  }

  ListNode<T> *tmp = head_;
  ListNode<T> *last;
  while(tmp) {
    last = tmp;
    tmp = tmp->get_next();
  }
  last->set_next(new_node);
  return new_node;
}

template<typename T>
ListNode<T> *List<T>::new_item_front(T& item) {
  auto *new_node = new ListNode<T>();
  new_node->set_next(head_);
  new_node->set_data(item);
  head_ = new_node;
  return new_node;
}

template<typename T>
ListNode<T> *List<T>::insert_after(ListNode<T> *node, T& item) {
  auto new_node = new ListNode<T>();
  new_node->set_data(item);
  node->insert_after(new_node);
  return new_node;
}

template<typename T>
void List<T>::print() {
  ListNode<T> *tmp = head_;
  while(tmp) {
    tmp->print();
    std::cout << std::endl;
    tmp = tmp->get_next();
  }
}

#endif
