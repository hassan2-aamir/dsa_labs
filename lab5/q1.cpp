#include <string>
#include <iostream>
using namespace std;

class Stack{
    public:
        int top;
        char* elements = new char[10];

        Stack(){
            top=0;
        }

        bool isEmpty(){
            return top==0;
        }

        bool isFull(){
            return top==10;
        }

        void Push(char element){
            if (! isFull()) elements[top++]=element;    
            else cout<<"Stack full !"<<endl;
        }

        char Pop(){
            if(!isEmpty()) return elements[--top];
            else cout<<"nothing in list!"<<endl;
        }

        void Clear(){
            char* temp = elements;
            delete[] temp;
            elements=new char[10];
            top=0;
        }

        char Peak(){
            if (! isEmpty())
            return elements[top-1];
            else
            return ' ';
        }

};

void checkFunction(string str){
    Stack *braceStack=new Stack();
    int brackets=0;
    for(int i=0;i<str.length();i++){
        if(str[i] == '{' or str[i] == '(' or str[i] == '[' ){
            braceStack->Push(str[i]);
        }
        else if (str[i] == '}'){
            if(braceStack->Peak()=='{'){

            }
        }
    }

}
int main(){

}