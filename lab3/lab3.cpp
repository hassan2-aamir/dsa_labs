#include <iostream>
using namespace std;


class ListNode{
public:
	int data;
	ListNode *next;
};

class LinkedList{
    public:
        ListNode *start=new ListNode(); // special variable which stores address of the head node.
        ListNode *last=new ListNode(); // special variable which stores address of the last node.

        ListNode *PredLoc_=new ListNode(); //to be used by Search(value) method to store address of logical predecessor of value in a list.
        ListNode *Loc_=new ListNode(); //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL.

        LinkedList(){
            start= nullptr;
		    PredLoc_=nullptr;
		    Loc_=nullptr;
            last=nullptr;
        };

        bool IsEmpty(){
            return start== nullptr;
        };

        void InsertAtStart(int value){
            ListNode* new_node = new ListNode();//create new node

            new_node->data=value;//enter value of new node
            new_node->next=start;//enter address to point to the previously first element

            if(last==nullptr){//check if list was empty and update last accordingly
                last=new_node;
            }
            
            start=new_node;//insert new node at start
            
        };

        void InsertAtEnd(int value){
            ListNode* new_node  = new ListNode();//create new node

            new_node->data=value;//enter value of new node
            new_node->next=nullptr;//at end so points to nothing

            if(start==nullptr){//check if list was empty and update last accordingly
                start=new_node;
                last=new_node;
            }
            else{
                last->next=new_node;//previously last element points to new_node
                last=new_node;//insert new node at last
            }
            
            
        };

        void PrintList(){
            if(!IsEmpty()){  //if not empty
                ListNode *curr = start; //start from 1st
	            while(curr!=nullptr){ //while not end
			        cout<<curr->data<<" "; //display data
                    curr=curr->next; //update to next node
                }
            }
            else{ //if empty
                cout<<"Nothing in list!"<<endl;
            }

        }

        void SearchList(int value){
            
            Loc_=start;//start from beginning
            PredLoc_=nullptr; //no previous at start

            if(IsEmpty()){
                return;
            }

            while (Loc_!=NULL and Loc_->data < value){
	            //Advance both predloc and loc
                PredLoc_ = Loc_;
                Loc_ = Loc_ -> next;
            }

            if(Loc_!=NULL and Loc_->data!=value){//value not found
                Loc_=nullptr;
            }
        };

        void InsertSorted(int value){ 
            SearchList(value);
            if (Loc_!=nullptr){ //check using loc
                cout<<"list already has this number"<<endl;
                return;
            }
            else{ //insert with help of predloc
                ListNode* new_node = new ListNode();

                new_node->data=value; //insert valueof new node

                if(IsEmpty()){ //empty list
                    start=new_node;
                    last=new_node;
                    new_node->next = nullptr;
                }
                else if (PredLoc_ == nullptr) {  // Insertion at the start of the list
                    new_node->next = start;
                    start = new_node;
                }
                else {  // General case: Insertion after PredLoc_
                    new_node->next = PredLoc_->next;  // Point to what PredLoc_ was pointing to
                    PredLoc_->next = new_node;

                    if (new_node->next == nullptr) {  // If the new node is now the last node
                        last = new_node;
                    }
                }

            }
        };

        void Delete(int value){
            SearchList(value);
            if (IsEmpty() or Loc_==nullptr){
                cout<<"no such value to delete";
                return;
            }
            else{
                if(PredLoc_==nullptr){
                    ListNode* startNext =start->next;
                    delete start;
                    start=startNext;
                    if (start == nullptr) {
                        last = nullptr;  // List is now empty
                    }   
                }

                else {  // Deleting a middle or last node
                    PredLoc_->next = Loc_->next;
                    if (Loc_ == last) {
                        last = PredLoc_;  // Update last if we're deleting the last node
                    }
                    delete Loc_;
                }
                Loc_ = nullptr;
            }
        }

        ~LinkedList(){
            ListNode* curr = start;
            while(curr!=nullptr){
                ListNode* temp = curr;  // Save the current node
                curr = curr->next;      // Move to the next node
                delete temp;  
            }
            start = nullptr;
            last = nullptr;
        }






};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert at Start" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert in Sorted Order" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Search" << endl;
        cout << "6. Print List" << endl;
        cout<<"7. Destroy List" <<endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at start: ";
                cin >> value;
                list.InsertAtStart(value);
                cout << "Value inserted at start." << endl;
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.InsertAtEnd(value);
                cout << "Value inserted at end." << endl;
                break;

            case 3:
                cout << "Enter value to insert in sorted order: ";
                cin >> value;
                list.InsertSorted(value);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                list.Delete(value);
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                list.SearchList(value);
                if (list.Loc_ != nullptr) {
                    cout << "Value found in the list." << endl;
                } else {
                    cout << "Value not found in the list." << endl;
                }
                break;

            case 6:
                cout << "Current list: ";
                list.PrintList();
                cout << endl;
                break;

            case 7:
                cout<< "Destroying list";
                list.~LinkedList();
                cout<<endl;
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}



