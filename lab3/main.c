#include <stdio.h>
#include <stdlib.h>
#include "monster.h"

int main() {
  struct army_type *army = create_army();
  for(int i = 0; i < 10; i++) {
    add_monster(army, create_monster("Pikachu", 100));
  }
  display_army(army);
  delete_army(army);
  return 0;
}