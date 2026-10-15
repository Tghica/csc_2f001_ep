#include <stdlib.h>
#include <stdio.h>

#define SIZE_OF_NAME 20

struct monster_type {
    char *name;
    int health;
};

struct monster_type *create_monster(char *name, int health);

void display_monster(struct monster_type *monster);

void delete_monster(struct monster_type *monster);