#include <string>

struct list_t;

void error(std::string str);

struct node_t{
  virtual node_t* eval();
  virtual node_t* apply(list_t* list);
  virtual std::string to_string();
  virtual list_t* as_list();
};

