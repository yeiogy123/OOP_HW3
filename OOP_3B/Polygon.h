//
// Created by User on 2021/4/14.
//

#ifndef OOP_HW03BB_POLYGON_H
#define OOP_HW03BB_POLYGON_H
//
// Created by User on 2021/4/13.
//
#include<cmath>
#include"LinkedList.h"
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}
int orientation(Point p, Point q, Point r)
{
    // reference from http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    int val = (q.y - p.y) * (r.x - q.x)-(q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    //Find four orientations needed for general and special case
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case- line segment A crosses  line segment B, looks like shape X.
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases-one end point of line segment A(p1-q1 or p2-q2) lie s on line segment B(p2-q2 or p1-q1), looks like shape T.
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}
class Polygon{
private:
    LinkedList vertexList;
public:
    Polygon(){
        cout << "Construct Polygon"<<endl;
        vertexList=LinkedList();
    }
    ~Polygon(){
        cout << "Destruct Polygon"<<endl;
        //vertexList.~LinkedList();
    }
    void setPolygon(Point pts[], int size, const int status[]){
        vertexList.clear();
        for(int i = 0 ; i < size ; i++){
            if(status[i] == 1){
                vertexList.insertToNext(pts[i]);
                vertexList.pointToNext();
            }else if(status[i] == 2){
                vertexList.insertToPrev(pts[i]);
                vertexList.pointToPrev();
            }
        }

    }
    Polygon * splitPolygon(){
        const int originalSize = vertexList.getSize();
        const int M = (int)floor(originalSize/2)+1;
        cout<<"copy to clone"<<endl;
        Point clonePoint[M];
        int time = 0;
        while(time < M){
            clonePoint[time] = vertexList.getCurrentPoint();
            vertexList.pointToNext();
            time++;
        }
        int least = M;
        while(least < originalSize){
            vertexList.deleteCurrentNode();
            least++;
        }
        vertexList.pointToPrev();
        int status[M];
        for(int i = 0 ; i < M ; i++)
            status[i] = 1;
        Polygon *clone = new Polygon();
        clone->setPolygon(clonePoint,M,status);
        return clone;
    }
    bool isCollide(Polygon& inpolygon){
        int time = 0;
        const int size = inpolygon.vertexList.getSize();
        while(time <= size) {
            Point ptA,ptB;
            ptA = inpolygon.vertexList.getCurrentPoint();
            inpolygon.vertexList.pointToNext();
            ptB = inpolygon.vertexList.getCurrentPoint();
            if(isEdgeIntersect(ptA,ptB)){
                return true;
            }
            time++;
        }
        return false;
    }
    bool isEdgeIntersect(const Point& ptA, const Point& ptB){
        Point polystart, polyend;
        bool flag=false;
        int count=0;
        int size=vertexList.getSize();
        if(size>=3)
        {
            count=0;
            while(count<=size)
            {
                polystart=vertexList.getCurrentPoint();
                vertexList.pointToNext();
                polyend=vertexList.getCurrentPoint();

                flag=doIntersect(ptA, ptB, polystart, polyend);
                if(flag){
                    cout<<"[("<<ptA.x<<","<<ptA.y<<")"<<"to"<<"("<<ptB.x<<","<<ptB.y<<")"<<"is collided with"<<"("<<polystart.x<<","
                    <<polystart.y<<")"<<"to"<<"("<<polyend.x<<","<<polyend.y<<")]"<<endl;
                    break;
                }
                count++;
            }
        }
        else
            cout<<"This is not a polygon"<<endl;
        return flag;
    }
    void out(){
        vertexList.out();
    }
};

#endif //OOP_HW03BB_POLYGON_H
