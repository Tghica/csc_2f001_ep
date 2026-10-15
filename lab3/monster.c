#include <stdlib.h>
#include <stdio.h>
#include "monster.h"

struct monster_type *create_monster(char *name, int health) {
  struct monster_type *my_new_monster = malloc(sizeof *my_new_monster);
  my_new_monster->name = malloc(sizeof(*name) * SIZE_OF_NAME);
  for (int i = 0; i < SIZE_OF_NAME - 1 && name[i] != '\0'; i++) {
    my_new_monster->name[i] = name[i];
  }
  my_new_monster->name[SIZE_OF_NAME - 1] = '\0';
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