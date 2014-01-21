#include "Mesh.h"
#include <fstream>

using namespace std;


Mesh::Mesh(){
    numVerts = numFaces = nProperties = 0;
}

Mesh::~Mesh(){

}

void Mesh::ReadData(void) {
    std::cout << "Enter file name: " << endl;
    std::string filename;
    while (!(std::cin >> filename))  {
        std::cin.get();
        std::cout << "Invaild file name!\n";
        std::cout << "Enter file name: " << endl;
        
    }
    name = filename;
    string ext = filename.substr( filename.find('.')+1);
     if (ext == "ply") {
         ReadPlyFile(filename);
     } else {
         cout << " Invaild mesh type!\n";
         return;
     }

}

void Mesh::ReadPlyFile(string fname)   
{   
    fstream inStream;   
    inStream.open(fname.c_str(),ios::in);   
    if(inStream.fail()||inStream.eof())   
    {   
        cout << "can't open file or eof:" << fname << endl;   
        //makeEmpty();   
        return;   
    }   

    char *headerTemp=new char[100];   
    inStream.getline(headerTemp, 4, '\n');//read one line   
    if(!strcmp(headerTemp,"ply"))   
        cout << "congratulations!" << endl;   
    else{   
        cout << "failure!" << endl;   
        return;   
    }   

    inStream.getline(headerTemp,100,'\n');   

   // nProperties=-1;   
    while(strncmp(headerTemp,"end_header",10)!=0)//先对文件头进行解析   
    {   
        int vertexflag=0;   
        if(!strncmp(headerTemp,"element",7))//这行是element   
        { if(!strncmp(headerTemp+8,"vertex",6))//并且是vertex   
        {   
            numVerts=atoi(headerTemp+15);//找到了vertex的数目   
            do{   
                delete[] headerTemp;//清空headerTemp   
                char *headerTemp=new char[100];   
                inStream.getline(headerTemp,100,'\n');//读入文件的下一行   
                nProperties++;//对vertex的属性的个数进行计数   

            }while(!strncmp(headerTemp,"property",8));   
            vertexflag=1;//标志这次循环处理的是vertex那行   
        }   
        else //是face那行的   
            numFaces=atoi(headerTemp+13);//找到face的数目   
        }   
        if(vertexflag==0)   
        {   
            delete[] headerTemp;//清空headerTemp   
            char *headerTemp=new char[100];   
            inStream.getline(headerTemp,100,'\n');//读入文件的下一行   
        }   

    }   
    //<<<<<<<<<<<<<<<<<<<以上对文件头进行了解析，提取了顶点的数目以及面的数目还有顶点的属性个数<<<<<<   
    //<<<<<<<<<<<<<<<<<<<下面读顶点和面<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                                                           
//     pt=new Point3[numVerts];   
//     face=new Face[numFaces];   
    double tempBuff; 
    Point pt;
    Face fc;
    for(int i=0; i<numVerts; i++)//读入顶点   
    {   
        inStream >> pt.x >> pt.y >> pt.z;
        vertices.push_back(pt);
        for(int p=0;p< nProperties-3;p++)   
            inStream >> tempBuff;   
    }   
    for(int f=0;f<numFaces;f++)//读入面的信息   
    {   
        int n = 0;
        inStream >> n;   
        for(int k=0;k<n;k++)   
            inStream >> fc.v0 >> fc.v1 >> fc.v2;   
        faces.push_back(fc);
    }   
    
    inStream.close();   

}   