#include <iostream>
#include "Node.h"
#include "Stack.h"
using namespace std;
int main() {
    Stack *newStack = new Stack();
    cout<<"input 1:push,2:pop,3:isempty,-1:shut down : ";
    int station ;
    while(cin>>station&&station != -1){
        if(station == 1){
            cout<<"please input item to push : ";
            int item;
            cin>>item;
            newStack->push(item);
        }else if(station == 2){
            int item = newStack->pop();
            if(item != -100000)
            cout<<"["<<item<<"]"<<"has already popped out"<<endl;
        }else if(station == 3) {
            newStack->empty();
        }else{
            cout<<"your input is wrong."<<endl;
        }
        cout<<"input 1:push,2:pop,3:isempty,-1:shut down : ";
    }
    cout<<"the program shut down."<<endl;
    delete newStack;
    return 0;
}
