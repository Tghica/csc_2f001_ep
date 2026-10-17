#include <stdlib.h>
#include <stdio.h>
#include "army.h"

struct army_type {
  struct monster_type** monsters;
  int top;
  int capacity;
};

struct army_type *create_army(){
  struct army_type* my_new_army = malloc(sizeof *my_new_army);
  my_new_army->top = 0;
  my_new_army->capacity = 0;
  return my_new_army;
}

void add_monster(struct army_type *army, struct monster_type *monster) {
  if (army->capacity == army->top && army->capacity != 0) {
    army->monsters = realloc(
      army->monsters,
      sizeof *army->monsters * army->capacity * 2
    );
    army->capacity *= 2;
  } else if (army->capacity == 0) {
    army->monsters = malloc(sizeof *army->monsters);
    army->capacity = 1;
  }

  army->monsters[army->top] = monster;
  army->top++;
}

void display_army(struct army_type *army) {
  for (int i = 0; i < army->top; i++) {
    display_monster(army->monsters[i]);
  }
}

void delete_army(struct army_type *army) {
  for (int i = 0; i < army->top; i++) {
    delete_monster(army->monsters[i]);
  }

  free(army->monsters);
  free(army);
}