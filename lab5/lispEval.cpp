#include "lispEval.h"
#include <iostream>

using namespace std;

void error(string str) __attribute__((noreturn));

void error(string str) {
  cout << "Error: " << str << endl;
  exit(1);
}

node_t* node_t::eval(){
  return this;
}

node_t* apply(list_t* list){
  error("Apply no work :( it crapeted");
}

string to_string(){
  cout<<"???";
}

list_t* as_list(){
  error("No se puede list yet :( it crapeted");
}