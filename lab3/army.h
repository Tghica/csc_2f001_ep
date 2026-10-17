#include "monster.h"

struct army_type;

struct army_type *create_army();

void add_monster(struct army_type *army, struct monster_type *monster);

void display_army(struct army_type *army);

void delete_army(struct army_type *army);

