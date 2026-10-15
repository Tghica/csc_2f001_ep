#include <stdio.h>
#include <stdlib.h>
#include "monster.h"

int main() {
  char name[] = "pikachu-x";
  struct monster_type **pic = malloc(10 * sizeof *pic);
  for(int i = 0; i < 10; i++) {
    name[8] = '0' + i;
    pic[i] = create_monster(name, 10);
  }
  for(int i = 0; i < 10; i++)
    display_monster(pic[i]);
  for(int i = 0; i < 10; i++) 
    delete_monster(pic[i]);
  free(pic);
  return 0;
}