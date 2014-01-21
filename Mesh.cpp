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
    while(strncmp(headerTemp,"end_header",10)!=0)//�ȶ��ļ�ͷ���н���   
    {   
        int vertexflag=0;   
        if(!strncmp(headerTemp,"element",7))//������element   
        { if(!strncmp(headerTemp+8,"vertex",6))//������vertex   
        {   
            numVerts=atoi(headerTemp+15);//�ҵ���vertex����Ŀ   
            do{   
                delete[] headerTemp;//���headerTemp   
                char *headerTemp=new char[100];   
                inStream.getline(headerTemp,100,'\n');//�����ļ�����һ��   
                nProperties++;//��vertex�����Եĸ������м���   

            }while(!strncmp(headerTemp,"property",8));   
            vertexflag=1;//��־���ѭ���������vertex����   
        }   
        else //��face���е�   
            numFaces=atoi(headerTemp+13);//�ҵ�face����Ŀ   
        }   
        if(vertexflag==0)   
        {   
            delete[] headerTemp;//���headerTemp   
            char *headerTemp=new char[100];   
            inStream.getline(headerTemp,100,'\n');//�����ļ�����һ��   
        }   

    }   
    //<<<<<<<<<<<<<<<<<<<���϶��ļ�ͷ�����˽�������ȡ�˶������Ŀ�Լ������Ŀ���ж�������Ը���<<<<<<   
    //<<<<<<<<<<<<<<<<<<<������������<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                                                           
//     pt=new Point3[numVerts];   
//     face=new Face[numFaces];   
    double tempBuff; 
    Point pt;
    Face fc;
    for(int i=0; i<numVerts; i++)//���붥��   
    {   
        inStream >> pt.x >> pt.y >> pt.z;
        vertices.push_back(pt);
        for(int p=0;p< nProperties-3;p++)   
            inStream >> tempBuff;   
    }   
    for(int f=0;f<numFaces;f++)//���������Ϣ   
    {   
        int n = 0;
        inStream >> n;   
        for(int k=0;k<n;k++)   
            inStream >> fc.v0 >> fc.v1 >> fc.v2;   
        faces.push_back(fc);
    }   
    
    inStream.close();   

}   