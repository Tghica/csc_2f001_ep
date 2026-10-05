#include <stdio.h>

int sort_get_index(float tab[], int top, float val) {
    for (int index = 0; index < top; index++) {
        if (tab[index] > val) {
            return index;
        }
    }

    return top;
}

void sort_insert_at(float tab[], int i, int *top, float val){
    for( int j = *top; j >= i; j--){
    tab[j] = tab[j - 1];
  }
  tab[i] = val;
    (*top)++;
}

void sort_insert(float tab[], int *top, float val) {
    int index = sort_get_index(tab, *top, val);
        sort_insert_at(tab, index, top, val);
}

int nb_columns(){
  return 32;
}

int nb_lines(){
  return 16;
}

void grid_init(char grid[], char pixel) {
  for(int i = 0; i < nb_lines() * nb_columns(); i++){
    grid[i] = pixel;
  }
}

void plot_point(char grid[], int x, int y, char pixel) {
  if(x < 0 || x >= nb_columns() || y < 0 || y >= nb_lines()){
    printf("error: point out of bounds\n");
    return;
  }
  grid[y * nb_columns() + x] = pixel;
}

void plot_vline(char grid[], int x, float fy0, float fy1, char pixel) {
  int y0 = (int) fy0;
  int y1 = (int) fy1;
  if(fy0 - y0 >= 0.5){
    y0++;
  }
  if(fy1 - y1 >= 0.5){
    y1++;
  }
  if(fy0 == y0 - 0.5){
    y0--;
  }
  
  for(int y = y0; y <= y1; y++){
    plot_point(grid, x, y, pixel);
  }
}

typedef struct {
  float x;
  float y;
} point;

void plot_poly_sweep(char grid[], point p[], int n, int x, char pixel) {
  float vlines[n * 4];
  int top = 0;

  printf("sweep %d:", x);
  for (int i = 0; i < n; i++) {
    int j = (i + n - 1) % n;

    if ((p[i].x <= p[j].x && p[i].x <= x && x < p[j].x) ||
        (p[j].x <= p[i].x && p[j].x <= x && x < p[i].x)) {
      float y = p[i].y + (x - p[i].x) *
                (p[j].y - p[i].y) / (p[j].x - p[i].x);
      sort_insert(vlines, &top, y);
    }
  }

  for (int i = 0; i < top; i++) {
    printf(" %f", vlines[i]);
  }
  printf("\n");

  for (int i = 0; i + 1 < top; i += 2) {
    plot_vline(grid, x, vlines[i], vlines[i + 1], pixel);
  }
}

void plot_poly(char grid[], point p[], int n, char pixel) {
  for (int x = 0; x < nb_columns(); x++) {
    plot_poly_sweep(grid, p, n, x, pixel);
  }
}

int main() {
  char my_grid[nb_lines() * nb_columns()];
  point p[] = {{2, 13}, {10, 13}, {30, 7}, {10, 1}, {2, 1}, {18, 7}};

  grid_init(my_grid, '.');
  plot_poly(my_grid, p, sizeof(p) / sizeof(p[0]), '#');

  for (int y = 0; y < nb_lines(); y++) {
    for (int x = 0; x < nb_columns(); x++) {
      putchar(my_grid[y * nb_columns() + x]);
    }
    putchar('\n');
  }

  return 0;
}