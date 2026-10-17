#include <stdlib.h>
#include <stdio.h>

#define NAME_SIZE 256
#define CAPACITY_SIZE 64

struct monster_type;

struct army_type;

struct monster_type *create_monster(char *name, int health);

void display_monster(struct monster_type *monster);

void delete_monster(struct monster_type *monster);

struct army_type *create_army();

void add_monster(struct army_type *army, struct monster_type *monster);

void display_army(struct army_type *army);

void delete_army(struct army_type *army);