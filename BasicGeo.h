#ifndef MASHPARAM_BASICGOE_H
#define  MASHPARAM_BASICGOE_H

typedef  unsigned int VERTEX_INDEX ;
const double kInitDouble = 0.0; 
const VERTEX_INDEX kInitIndex = 0;

class Point {
public:
    Point() { x = y = z = kInitDouble; }
    double x;
    double y;
    double z;
    
};

class Verctor3D {
public:
    Verctor3D () { x = y = z = kInitDouble; }

    double x;
    double y;
    double z;
    
};

class Face {
public:
    Face() { v0 = v1 = v2 = kInitIndex; area = kInitDouble; }

    VERTEX_INDEX v0;
    VERTEX_INDEX v1;
    VERTEX_INDEX v2;
    Verctor3D normal;
    double  area;
        
};
class Line {
public:
    Line() { v0 = v1 = kInitIndex; length = kInitDouble; }

    VERTEX_INDEX v0;
    VERTEX_INDEX v1;
    double length;
};


#endif  //MASHPARAM_BASICGOE_H