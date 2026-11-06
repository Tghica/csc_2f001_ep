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

node_t* node_t::apply(list_t* list){
  error("No se puede we don no yet :( it crapeted");
}

string node_t::to_string(){
  return "???";
}

list_t* node_t::as_list(){
  error("No se puede list yet :( it crapeted");
}

uintptr_t node_t::int_value(){
  error("No se puede no integer here :( it crapeted");
}

bool node_t::is(std::string id) {
  return false;
}

string integer_t::to_string(){
  return std::to_string(this->val);
}

integer_t::integer_t(int x){
  this->val = x;
}

list_t::list_t(){
  this->elements = nullptr;
  this->capacity = 0;
  this->nb_elements = 0;
}

list_t* list_t::as_list(){
  return this;
}

node_t* list_t::eval(){
  node_t* operation = this->at(0)->eval();
  return operation->apply(this);
}

size_t list_t::size(){
  return this->nb_elements;
}

node_t* list_t::at(size_t i){
  if(i >= this->nb_elements)
    error("Access element out of bounds :( it crapeted");
  return *(this->elements + i);
}

void list_t::set_at(size_t i, node_t* value){
  if(i >= this->nb_elements)
    error("Tried to modify element out of bounds :( it crapeted");
  *(this->elements + i) = value;
}

void list_t::append(node_t* value) {
  if(this->capacity <= this->nb_elements) {
    //we have to make the list larger
    size_t new_capacity = capacity == 0 ? 4 : capacity * 2;
    node_t** new_elements = new node_t*[new_capacity];
    
    for(size_t i = 0; i < this->nb_elements; i++) {
      *(new_elements + i) = *(this->elements + i);
    }
    this->elements = new_elements;
    this->capacity = new_capacity;
  }
  *(this->elements + this->nb_elements) = value;
  this->nb_elements++;
}

string list_t::to_string() {
  string s = "(";
  for(size_t i = 0; i < this->nb_elements; i++) {
    s = s + (*(this->elements + i))->to_string() + " ";
  }
  s[s.size() - 1] = ')';
  return s;
}

keyword_t::keyword_t(){
  this->id = "";
}

string keyword_t::to_string(){
  return "<" + this->id + ">";
}

add_t::add_t(){
  this->id = "+";
}

node_t* add_t::apply(list_t* list) {
  return new integer_t(list->at(1)->eval()->int_value() + list->at(2)->eval()->int_value());
}

uintptr_t integer_t::int_value(){
  return this->val;
}

symbol_t::symbol_t(string symbol){
  this->id = symbol;
}

bool symbol_t::is(std::string id){
  return (this->id == id);
}

string symbol_t::to_string(){
  return this->id;
}

void frame_t::set(node_t* sym, node_t* value){
  bool ok = true;
  for(size_t i = 0; i < this->nb_elements; i++) {
    if(this->at(i)->as_list()->at(0)->to_string() == sym->to_string()) {
      this->at(i)->as_list()->set_at(1, value);
      ok = false;
    }
  }
  if(ok){
    list_t* binding = new list_t;
    binding->append(sym);
    binding->append(value);
    this->append(binding);
  }
}

node_t* frame_t::get(node_t* sym){
  for(size_t i = 0; i < this->nb_elements; i++) {
    if(this->at(i)->as_list()->at(0)->to_string() == sym->to_string()) {
      return this->at(i)->as_list()->at(1);
    }
  }
  error("No se puede no element with that symbol :( it crapeted")
}