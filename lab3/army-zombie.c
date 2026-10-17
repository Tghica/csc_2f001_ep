#include <stdlib.h>
#include <stdio.h>
#include "army.h"

struct node_type {
  struct node_type* nxt;
  struct monster_type *monster;
};


struct army_type {
  struct node_type* firstNode;
  int capacity;
  int stars;
};

struct army_type *create_army(){
  struct army_type* my_new_army = malloc(sizeof *my_new_army);
  my_new_army->capacity = 0;
  my_new_army->firstNode = NULL;
  return my_new_army;
}

void add_monster(struct army_type *army, struct monster_type *monster) {
  if(army->capacity == 0) {
    army->firstNode = malloc(sizeof(struct node_type));
    army->firstNode->monster = monster;
    army->firstNode->nxt = NULL;
  } else{
    struct node_type *pointCur = army->firstNode;
    while(pointCur->nxt != NULL) {
      pointCur = pointCur->nxt;
    }
    pointCur->nxt = malloc(sizeof(struct node_type));
    pointCur->nxt->monster = monster;
    pointCur->nxt->nxt = NULL;
  }
  army->capacity++;
}

void display_army(struct army_type *army) {
  printf("This is a %d stars army\n", army->stars);

  struct node_type *pointCur = army->firstNode;
  while (pointCur != NULL) {
    display_monster(pointCur->monster);
    printf("\n");
    pointCur = pointCur->nxt;
  }
}

void delete_army(struct army_type *army) {
  struct node_type *pointCur = army->firstNode;

  while (pointCur != NULL) {
    struct node_type *nextNode = pointCur->nxt;
    delete_monster(pointCur->monster);
    free(pointCur);
    pointCur = nextNode;
  }

  free(army);
}