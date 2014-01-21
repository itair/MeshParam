#ifndef MASHPARAM_MESH_H
#define  MASHPARAM_MESH_H

#include "BasicGeo.h"

#include <iostream>
#include <vector>
#include <string>

class Mesh{
public:
    Mesh();    
    ~Mesh();
    void ReadData(void);
    void ReadPlyFile(std::string) ;

    void InitMesh(void);
    void SaveMesh(void);


private:
    std::string name;
    std::vector<Point> vertices;
    std::vector<Face> faces;
    std::vector<Line> edges;
    int numVerts;
    int numFaces;
    int nProperties;

};








#endif  //MASHPARAM_MESH_H