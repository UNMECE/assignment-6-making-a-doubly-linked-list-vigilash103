#ifndef CORRDINATE_H
#define CORRDINATE_H

struct _coordinate
{
  float x;
  float y;
  int coordId;
  struct _coordinate *next;
  struct _coordinate *previous;
};
typedef struct _coordinate Coordinate;

// add_coordinate: add's a coordinate to the end of the linked list
void addCoordinate(Coordinate *listEnd, float x, float y);

// forward_display: displays all coordinates from beginning to end
void forwardDisplay(Coordinate *listBeginning);

// backwards_display: displays all coordinates from end to beginning
void backwardDisplay(Coordinate *listEnd);

// delete_coordinate: removes a coordinate from the linked list (free memory!)
void deleteCoordinate(Coordinate *listBeginning, int coordIdToDelete);

// list_length: return the length of the list
int listLength(Coordinate *listBeginning);

// closest_to: find the coordinate that is closest to the given x, y and output the distance between the 2
void closestTo(Coordinate *listBeginning, float x, float y);

#endif // !CORRDINATE_H