#include <stdlib.h>
#include <stdio.h>
#include "monster.h"



struct monster_type {
    char name[NAME_SIZE];
    int health;
};

struct monster_type *create_monster(char *name, int health) {
  struct monster_type *my_new_monster = malloc(sizeof *my_new_monster);
  int i;
  for (i = 0; i < NAME_SIZE - 1 && name[i] != '\0'; i++) {
    my_new_monster->name[i] = name[i];
  }
  my_new_monster->name[i] = '\0';
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