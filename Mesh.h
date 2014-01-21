#ifndef MASHPARAM_MESH_H
#define  MASHPARAM_MESH_H

#include "BasicGeo.h"

#include <iostream>
#include <vector>

class Mesh{
public:
    Mesh();
    ~Mesh();

private:
    std::vector<Point> vertices;
    std::vector<Face> patchs;
    std::vector<Line> edges;

};








#endif  //MASHPARAM_MESH_H