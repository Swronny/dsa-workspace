// EfficientTruckloads.h

#ifndef EFFICIENTTRUCKLOADS_H
#define EFFICIENTTRUCKLOADS_H

#include <vector>

class EfficientTruckloads {
private:
    std::vector<int> memo;

public:
    int numTrucks(int numCrates, int loadSize);
};

#endif