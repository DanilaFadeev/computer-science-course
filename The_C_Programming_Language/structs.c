#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rectangle {
  struct point bottomLeft;
  struct point topRight;
};

struct point create_point(int x, int y) {
  struct point pt;
  pt.x = x;
  pt.y = y;

  return pt;
}

int pt_in_rectange(struct rectangle rect, struct point pt) {
  return pt.x >= rect.bottomLeft.x && pt.x <= rect.topRight.x
      && pt.y >= rect.bottomLeft.y && pt.y <= rect.topRight.y;
}

void print_point(struct point* pt) {
  // Alternative way - printf("Point: (x: %d, y: %d)\n", (*pt).x, (*pt).y);
  printf("Point: (x: %d, y: %d)\n", pt->x, pt->y);
}

int main(int argc, char* argv[]) {
  struct point pt1 = { 100, 200 };
  printf("Struct point: (%d, %d)\n", pt1.x, pt1.y);

  struct point pt2 = { 200, 400 };
  struct rectangle rect;
  rect.bottomLeft = pt1;
  rect.topRight = pt2;

  printf("Rectangle top right x value: %d\n", rect.topRight.x);

  int isPointInRectangle = pt_in_rectange(rect, create_point(150, 300));
  printf("Point (150, 300) in rect: %s\n", isPointInRectangle ? "true" : "false");

  struct rectangle *rect_ptn = &rect;
  // these forms are equals: rect_ptn->topRight == (*rect_ptn).topRight
  printf("When rect is struct pointer (%d, %d)\n", rect_ptn->topRight.x, rect_ptn->topRight.y);

  print_point(&pt1);

  return 0;
}