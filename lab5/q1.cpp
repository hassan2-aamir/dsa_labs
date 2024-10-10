#include <string>
#include <iostream>
using namespace std;

//stack with specified funnctions
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

//checks string
void checkFunction(string str){
    Stack *braceStack=new Stack();
    int i;
    char _;
    for(i=0;i<str.length();i++){ //traverse equation
        if(str[i] == '{' or str[i] == '(' or str[i] == '[' ){ //add brackets to stack
            braceStack->Push(str[i]);
        }
        else if (str[i] == '}'){ // pop and check if opening bracket in stack
            if(braceStack->Peak()=='{'){
                _=braceStack->Pop();                
            }
            else{ //if no opening bracket wrong
                cout<<"This expression is not correct."<<endl; 
                break;
            }
        }
        else if (str[i] == ')'){ // pop and check if opening bracket in stack
            if(braceStack->Peak()=='('){
                _=braceStack->Pop();                
            } 
            else{ //if no opening bracket wrong
                cout<<"This expression is not correct."<<endl;
                break;
            }
        }
        else if (str[i] == ']'){ // pop and check if opening bracket in stack
            if(braceStack->Peak()=='['){
                _=braceStack->Pop();                
            }
            else{ //if no opening bracket wrong
                cout<<"This expression is not correct."<<endl; 
                break;
            }
        }
        else{
            continue;
        }
    }
    if (i==str.length()){ //check if gone through whole loop
        if(!braceStack->isEmpty()){ //if still something so not correct
            cout<<"This expression is not correct"<<endl; 
        }
        else{ //stack is empty
            cout<<"This expression is correct";
        }
    }

}
int main(){
    string sin;
    cout<<"Enter string: ";
    cin>>sin;

    checkFunction(sin);
}