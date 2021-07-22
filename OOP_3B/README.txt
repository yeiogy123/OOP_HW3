1.姓名：龐懋翔
2.學號：407235049
3.e-mail:yeiogy123@yahoo.com.tw
4.完成項目：
C++:class Polygon class LinkedList main 
makefile
Polygon.cpp + Polygon.h
LinkedList.cpp + LinkedList.h
main.cpp
polydata.txt
5.[備註]:在class Polygon中的III. void setPolygon(Point pts[], int size)；我有改變函式參數，
變成void setPolygon(Point pts[], int size, const int status[])，其中int status[]為記錄每一個輸入進來的node為1或2，
判斷在setPolygon時如何存取至LinkedList中，而在 Polygon* splitPolygon()中，若要新增一個複製的Polygon，傳入至setPolygon的status[]則全部為1，
因為LinkedList順序已經成為固定的。
在class Polygon 中，有多寫一個void out()，會呼叫我在class LinkedList中多寫的out()函式，功能為拿來輸出目前的circular double linked list