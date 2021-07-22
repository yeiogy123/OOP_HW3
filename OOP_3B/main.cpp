#include <fstream>
#include "Polygon.h"
#define MAX 1024
int main() {
    int i = 0, mode, status[MAX], status2[MAX];
    const char *FileName = "polydata.txt";
    ifstream InputFile;
    InputFile.open(FileName);
    Point point[MAX],point2[MAX];
    Polygon *polygon1 = new Polygon();
    Polygon *polygon2 = new Polygon();
    cout<<"[insert polygon 1]"<<endl;
    while(1){
        InputFile >> mode;
        if(mode == -1)
            break;
        status[i] = mode;
        InputFile >> point[i].x;
        InputFile >> point[i].y;
        cout<<"("<<point[i].x<<","<<point[i].y<<")"<<endl;
        i++;
    }
    polygon1->setPolygon(point,i,status);
    cout<<"[output the polygon 1]"<<endl;
    polygon1->out();
    i = 0;
    cout<<"[insert polygon 2]"<<endl;
    while(1){
        InputFile >> mode;
        if(mode == -1)
            break;
        status2[i] = mode;
        InputFile >> point2[i].x;
        InputFile >> point2[i].y;
        cout<<"("<<point2[i].x<<","<<point2[i].y<<")"<<endl;
        i++;
    }
    polygon2->setPolygon(point2,i,status2);
    cout<<"[output the polygon 2]"<<endl;
    polygon2->out();
    cout<<"[both of two polygon set successfully]"<<endl;
    bool Collide = polygon1->isCollide(*polygon2);
    if(!Collide)
        cout<<"[Polygon 1 is not collided with Polygon 2.]"<<endl;
    else
        cout<<"[Polygon1 is collided with Polygon2.]"<<endl;
    Polygon * copyPolygon;
    copyPolygon = polygon1->splitPolygon();
    cout<<"[clone:]"<<endl;
    copyPolygon->out();
    cout<<"[polygon1:]"<<endl;
    polygon1->out();
    if(!copyPolygon->isCollide(*polygon2))
        cout<<"[Clone Polygon 1 is not collided with Polygon 2.]"<<endl;
    else
        cout<<"[Clone Polygon 1 is collided with Polygon2.]"<<endl;
    polygon1->~Polygon();
    polygon2->~Polygon();
    copyPolygon->~Polygon();
    InputFile.close();
}
