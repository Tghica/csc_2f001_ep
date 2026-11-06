#include <iostream>
#include "lispEval.h"

using namespace std;

int main() {
  node_t* add = new add_t;
  list_t* ast = new list_t;

  ast->append(add);
  ast->append(new list_t);
  ast->at(1)->as_list()->append(add);
  ast->at(1)->as_list()->append(new integer_t { 1 });
  ast->at(1)->as_list()->append(new integer_t { 2 });
  ast->append(new integer_t { 3 });

  std::cout << ast->to_string() << " => " << ast->eval()->to_string() << std::endl;
  // should output (<+> (<+> 1 2) 3)
  std::cout << ast->to_string() << " => " << ast->eval()->to_string() << std::endl;
  return 0;
}