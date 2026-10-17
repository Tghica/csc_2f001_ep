#include <stdlib.h>
#include <stdio.h>
#include "monster.h"



struct monster_type {
    char name[NAME_SIZE];
    int health;
};

struct army_type {
  struct monster_type** monsters; // a pointer to an array, where each element of the array is a pointer to a monster
  int top;                   // where you have the last monster in the array
  int capacity;              // the capacity of the array
};

struct monster_type *create_monster(char *name, int health) {
  struct monster_type *my_new_monster = malloc(sizeof *my_new_monster);
  for (int i = 0; i < NAME_SIZE - 1 && name[i] != '\0'; i++) {
    my_new_monster->name[i] = name[i];
  }
  my_new_monster->name[NAME_SIZE - 1] = '\0';
  my_new_monster->health = health;
  return (my_new_monster);
}

void display_monster(struct monster_type *monster) {
  for(char *i = monster->name; *i != '\0'; i++)
    printf("%c", *i);
  printf("\n%d", monster->health);
}

void delete_monster(struct monster_type *monster) {
  free(monster);
}

struct army_type *create_army(){
  struct army_type* my_new_army = malloc(sizeof *my_new_army);
  struct monster_type *my_new_monster = malloc(sizeof *my_new_monster);
  my_new_army->monsters = malloc(sizeof *my_new_monster * CAPACITY_SIZE);
  my_new_army->top = 0;
  return my_new_army;
}

void add_monster(struct army_type *army, struct monster_type *monster) {
  army->monsters[army->top] = monster;
  army->top++;
}

void display_army(struct army_type *army) {
  for (int i = 0; i < army->top; i++) {
    display_monster(army->monsters[i]);
  }
}

void delete_army(struct army_type* army) {
  free(army);
}