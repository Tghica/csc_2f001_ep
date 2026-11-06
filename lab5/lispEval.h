#include <string>
#include <cstdint>

struct node_t;

struct list_t;

struct frame_t;

struct node_t{
  virtual node_t* eval(frame_t* frame);
  virtual node_t* apply(list_t* list, frame_t* frame);
  virtual std::string to_string();
  virtual list_t* as_list();
  virtual uintptr_t int_value();
  virtual bool is(std::string id);
};

struct keyword_t : node_t{
  std::string id;
  keyword_t();
  std::string to_string();
};

struct add_t : keyword_t{
  add_t();
  node_t* apply(list_t* list, frame_t* frame);
};

struct less_t : keyword_t{
  less_t();
  node_t* apply(list_t* list, frame_t* frame);
};

struct while_t : keyword_t{
  while_t();
  node_t* apply(list_t* list, frame_t* frame);
};

struct list_t : node_t{
  node_t** elements;
  size_t nb_elements;
  size_t capacity;
  list_t();
  node_t* eval(frame_t* frame);
  list_t* as_list();
  size_t size();
  node_t* at(size_t i);
  void set_at(size_t i, node_t* value);
  void append(node_t* value);
  std::string to_string();
};

void error(std::string str);

struct integer_t : node_t{
  integer_t(int x);
  uintptr_t val;
  std::string to_string ();
  uintptr_t int_value();
};

struct symbol_t : node_t {
    std::string id;
    symbol_t(std::string symbol);

    node_t* eval(frame_t* frame) override;
    bool is(std::string id);
    std::string to_string();
};

struct frame_t : list_t{
  void set(node_t* sym, node_t* value);
  node_t* get(node_t* sym);
};

struct set_t : keyword_t {
    set_t();
    node_t* apply(list_t* list, frame_t* frame) override;
};