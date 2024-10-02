#include <iostream>
using namespace std;


class ListNode{
public:
	int data; //data 
	ListNode *next; //nextPtr
    ListNode *prev; //previousPtr

    ListNode(){//create empty node
        data=NULL;
        next=NULL;
        prev=NULL;
    }
};

class DoublyLinkedList{
    public:
        ListNode *first ; //head node
        ListNode *last; //node at end
        ListNode *PredLoc_; //previous node while searching
	    ListNode *Loc_; //current node while searching

        DoublyLinkedList(){ //initialise empty list
		    first=NULL; 		
            last=NULL;
		    PredLoc_=NULL;	
            Loc_=NULL;
	    }

        bool isEmpty(){
            return first == NULL;//if first is null list is empty
        }

        void insertAtFront(int value){
            ListNode *newNode = new ListNode();
            newNode -> data = value;//store value
            if (isEmpty()){ //if first value in list first and last both to be updated
                first = newNode;
                last= newNode;

            }
            else{ //if already values only first needs to be updated
                newNode->next=first;
                first->prev=newNode;
                first=newNode;
            }
        }   

        void insertAtEnd(int value){
            ListNode *newNode = new ListNode();
            newNode -> data = value; //store value
            if (isEmpty()){ //if first value in list first and last both to be updated
                first = newNode;
                last= newNode;

            }
            else{ //if already values only last needs to be updated
                last->next=newNode;
                newNode->prev=last;
                last=newNode;
            }
        }

        void search(int value){

            //initialise loc and ploc
            Loc_ = first;
            PredLoc_ = NULL;

            while(Loc_ != NULL and Loc_->data<value){//search until we either reach end or insertion point or found point
                PredLoc_=Loc_;
                Loc_=Loc_->next;
            }

            if(Loc_!=NULL and Loc_->data!=value){ //if not found set Loc_ to NULL
                Loc_=NULL;
            }

        }

        void insertSorted(int value){
            search(value);

            if(Loc_!=NULL){ //value exists
                cout<<"List already has this value."<<endl;
                return;
            }

            ListNode* newNode = new ListNode(); //create node
            newNode->data=value; //Insert value
            if(isEmpty()){
                first=newNode;
                last=newNode;
                newNode->next = NULL;
            }
            else if (PredLoc_ == NULL){ //start of list
                newNode->next = first->next;
                first->prev=newNode;
                first=newNode;
            }
            else if(PredLoc_->next==NULL){ //end of list
                last->next=newNode;
                newNode->prev=last;
                last=newNode;
            }
            else{ //middle of list
                newNode->next = PredLoc_->next;
                newNode->prev=PredLoc_;
                PredLoc_->next->prev=newNode;
                PredLoc_->next=newNode;
            }

        }

        void deleteFront(){
            if (! isEmpty()){ //ensure not empty list
                ListNode*temp=first; //get first node
                first=first-> next;
                first->prev=NULL; //ensure no dangling pointers
                delete temp; //delete value
            }
        }

        void deleteLast(){

            if(! isEmpty()){//ensure not empty

                ListNode* temp=last;//get last node
                last=last->prev; 
                last->next=NULL; //ensure no dangling pointers
                delete temp; //delete last value
            }
        }


        void deleteVal(int value){
            if(isEmpty()){
                cout<<"Nothing in list"<<endl;
                return;
            }

            search(value);
            if (PredLoc_==NULL){ //head node to be deleted
                ListNode* temp = first;
                first=first->next;
                if (first != NULL) first->prev=NULL; //ensuring no dangling pointers
                delete temp;

            }
            else if(PredLoc_->next==NULL){ //at end
                ListNode* temp = last;
                last=last-> prev;
                last->next=NULL; //ensuring no dangling pointers
                delete temp;
            }

            else{ //in between
                ListNode* temp = Loc_;
                PredLoc_->next=Loc_->next;
                Loc_->next->prev=PredLoc_; //ensuring no dangling pointers
                delete temp;

            }
        }

        ~DoublyLinkedList(){
            ListNode* curr = first;
            if(! isEmpty()){
                while(curr!=NULL){
                    ListNode* temp = curr;  // Save the current node
                    curr = curr->next;      // Move to the next node
                    if (curr!= NULL) curr->prev=NULL; //avoid dangling pointers
                    delete temp;  
                }
                first = NULL;
                last = NULL;
                Loc_=NULL;
                PredLoc_=NULL;
            }
        }

        void PrintList(){
            if(!isEmpty()){  //if not empty
                ListNode *curr = first; //start from 1st
	            while(curr!=NULL){ //while not end
			        cout<<curr->data<<" "; //display data
                    curr=curr->next; //update to next node
                }
                cout<<endl;
            }
            else{ //if empty
                cout<<"Nothing in list!"<<endl;
            }

        }

        void reverse(){ //Q1
            if(! isEmpty()){

                ListNode *currPtr = first; //start from first
                ListNode *nextPtr; //to dtore next nodes
                last=currPtr; //update last

                while(currPtr->next!=NULL){ //traverse and update pointers
                    nextPtr = currPtr->next;
                    currPtr->next=currPtr->prev;
                    currPtr->prev=nextPtr;
                    currPtr=nextPtr;
                }

                //after reaching end update relevent node at end
                currPtr->next=currPtr->prev;
                currPtr->prev=NULL;
                first = currPtr;


            }
        }

        void swapNodes(int val1, int val2){
            //search and store val1 location
            search(val1);
            if(!Loc_){
                cout<<"val1 not found in list"<<endl;
                return;
            }
            ListNode* loc1 = Loc_;
            ListNode* ploc1 = PredLoc_;


            //search val2 location
            search(val2);
            if(!Loc_){
                cout<<"val2 not found in list"<<endl;
                return;
            }
            ListNode* loc2 = Loc_;
            ListNode* ploc2 = PredLoc_;

            if (loc1==first) first=loc2; //handle if node1 was at start
            else if(loc2==first) first=loc1; //handle if node2 was at start
            
            if (loc1==last) last=loc2; //handle if node1 at tail
            else if (loc2==last) last=loc1; //handle if node2 at tail

            //swap node 1 and 2
            ListNode* temp;
            
            temp = loc1->next;
            loc1->next = loc2->next;
            loc2->next = temp;


            //checks to ensure neither at end or start
            if (loc1->next != NULL)
                loc1->next->prev = loc1;
            if (loc2->next != NULL)
                loc2->next->prev = loc2;
        
            temp = loc1->prev;
            loc1->prev = loc2->prev;
            loc2->prev = temp;

            //checks to ensure neither at end or start
            if (loc1->prev != NULL)
                loc1->prev->next = loc1;
            if (loc2->prev != NULL)
                loc2->prev->next = loc2;
                    
                    

        }



};

int main(){
    DoublyLinkedList *myList = new DoublyLinkedList();

    myList->insertSorted(1);
    myList->insertSorted(7);
    myList->insertSorted(3);
    myList->insertSorted(5);
    myList->insertSorted(2);
    

    //cout<<"Before reverse: ";
    //myList->PrintList();

    //myList->reverse();

    //cout<<"After reverse: ";
    //myList->PrintList();

    cout<<"Before Swapping 1: ";
    myList->PrintList();

    int x,y;
    cout<<"Enter value1 for swapping: ";
    cin>>x;

    cout<<"Enter value2 for swapping: ";
    cin>>y;

    myList->swapNodes(x,y);

    cout<<"After Swapping 1: ";
    myList->PrintList();


}