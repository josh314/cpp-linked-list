#include <iostream>
#include "LinkedList.hpp"

struct ITEM {
  int data;
};

std::ostream& operator<<(std::ostream &out, ITEM i){
  std::cout << i.data;
}

int main() {
  int num_items = 10;
  ITEM *items = new ITEM[num_items];
  for(int i=0; i<num_items; ++i) {
    items[i].data = i;
  }
  
  std::cout << "We create 2 lists of the number 0-9," << std::endl;
  std::cout << "One by adding to the front of the list and the other to the end of the list" << std::endl;
  auto *forwards_list = new List<ITEM>;
  auto *backwards_list = new List<ITEM>;
  for(int i=0; i<num_items; ++i) {
    forwards_list->new_item_back(items[i]);
    backwards_list->new_item_front(items[i]);
  }

  std::cout << "Print out the forward list" << std::endl;
  forwards_list->print();
  std::cout << "Print out the backwards list" << std::endl;  
  backwards_list->print();

  delete forwards_list;
  delete backwards_list;

  return 0;
}

