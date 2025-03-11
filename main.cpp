#include <iostream>
#include <cstdlib>
#include <memory>
#include <cmath>
#include "coordinate.h"

// add_coordinate: add's a coordinate to the end of the linked list
void addCoordinate(Coordinate *listEnd, float x, float y) {
    Coordinate *newCoord = new Coordinate;
    newCoord->x = x;
    newCoord->y = y;
    newCoord->coordId = listEnd->coordId + 1;
    newCoord->next = nullptr;
    newCoord->previous = listEnd;
    listEnd->next = newCoord;
    listEnd = newCoord;

}

// forward_display: displays all coordinates from beginning to end
void forwardDisplay(Coordinate *listBeginning) {
    Coordinate *current = listBeginning;
    while (current != nullptr) {
        std::cout << "Coordinate " << current->coordId << ": (" << current->x << ", " << current->y << ")" << std::endl;
        current = current->next;
    }

}

// backwards_display: displays all coordinates from end to beginning
void backwardDisplay(Coordinate *listEnd) {
    Coordinate *current = listEnd;
    while (current != nullptr) {
        std::cout << "Coordinate " << current->coordId << ": (" << current->x << ", " << current->y << ")" << std::endl;
        current = current->previous;
    }

}

// delete_coordinate: removes a coordinate from the linked list (free memory!)
void deleteCoordinate(Coordinate *listBeginning, int coordIdToDelete) {
    Coordinate *current = listBeginning;
    while (current != nullptr) {
        if (current->coordId == coordIdToDelete) {
            if (current->previous != nullptr) {
                current->previous->next = current->next;
            } else {
                listBeginning = current->next;
            }
            if (current->next != nullptr) {
                current->next->previous = current->previous;
            }
            delete current;
            break;
        }
        current = current->next;
    }
}

// list_length: return the length of the list
int listLength(Coordinate *listBeginning) {
    int length = 0;
    Coordinate *current = listBeginning;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;

}

// closest_to: find the coordinate that is closest to the given x, y and output the distance between the 2
void closestTo(Coordinate *listBeginning, float x, float y) {
    Coordinate *current = listBeginning;
    float minDistance = 1000.0f;
    Coordinate *closest = nullptr;
    while (current != nullptr) {
        float distance = std::sqrt(std::pow(current->x - x, 2) + std::pow(current->y - y, 2));
        if (distance < minDistance) {
            minDistance = distance;
            closest = current;
        }
        current = current->next;
    }
    if (closest != nullptr) {
        std::cout << "Closest coordinate: " << closest->coordId << " at (" << closest->x << ", " << closest->y << ") with distance " << minDistance << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <number of coordinates>" << std::endl;
        return 1;
    }

    int numCoords = std::atoi(argv[1]);
    if (numCoords < 1) {
        std::cerr << "Invalid number of coordinates: " << numCoords << std::endl;
        return 1;
    }

    Coordinate *listBeginning = new Coordinate;
    Coordinate *listEnd = listBeginning;

    for (int i = 0; i < numCoords; i++) {
        float x = (rand() % 100);
        float y = (rand() % 100);
        addCoordinate(listEnd, x, y);
    }

    forwardDisplay(listBeginning);
    backwardDisplay(listEnd);

    closestTo(listBeginning, 50.0f, 50.0f);

    deleteCoordinate(listBeginning, 0);
    deleteCoordinate(listBeginning, numCoords - 1);

    forwardDisplay(listBeginning);
    backwardDisplay(listEnd);

    std::cout << "List length: " << listLength(listBeginning) << std::endl;

    // Clean up remaining coordinates
    while (listBeginning != nullptr) {
        Coordinate *next = listBeginning->next;
        delete listBeginning;
        listBeginning = next;
    }

    return 0;
}
