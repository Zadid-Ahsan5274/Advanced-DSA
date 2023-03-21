#include <iostream>

using namespace std;

class linkedlist
{
   struct Node{
      int data;
      Node *next;
   };

public:
   linkedlist(){
     head = NULL;
     tail = NULL;
  }



  void insertAtBeginning(int item){
      Node* location;
      location = new Node();
      location->data=item;
      location->next=head;
      head=location;
  }

  void insertAtEnd(Node* P){

  }

  void display(){
     Node *temp = new Node();
     temp=head;
     while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
     }
  }

  //~linkedlist();

private:
    Node* head;
    Node* tail;
};

int main(){
   linkedlist ll;
   ll.insertAtBeginning(5);
   ll.insertAtBeginning(2);
   ll.insertAtBeginning(3);
   ll.insertAtBeginning(10);
   ll.insertAtBeginning(7);
   ll.insertAtBeginning(45);
   ll.insertAtBeginning(63);
   ll.insertAtEnd(34);
   //ll.insertAtBeginning(2);
   ll.display();

   return 0;
}

    //void insertAtMiddle(int data);
    //void insertAtEnd(int data);
