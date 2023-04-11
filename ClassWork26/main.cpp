#include <iostream>

using namespace std;

class linkedlist{
   struct node{
      int data;
      node *next;
   };
   node *head;
   node *tail;

   public:
       linkedlist();
       void insert_beg(int item);
       void insert_end(int item);
       void delete_beg(int item);
       void delete_end(int item);
       void display();
};

       linkedlist::linkedlist(){
         head=NULL;
         tail=NULL;
       }
       void linkedlist::insert_beg(int item){
         node *temp = new node;
         temp->data=item;
         temp->next=head;
         if(head==NULL){
            tail=temp;
         }
         head=temp;
       }

       void linkedlist::insert_end(int item){
         node *temp = new node;
         temp->data=item;
         temp->next=NULL;
         if(head==NULL){
            head=temp;
         }
         else{
            tail->next=temp;
         }
        tail=temp;
       }

       void linkedlist::delete_beg(int item){
          node *temp=new node;
          temp=head;
           head=head->next;
          delete temp;
       }


       void linkedlist::delete_end(int item){
          node *currentnode = new node;
          node *previous = new node;
          currentnode = head;
          while(currentnode->next!=NULL){
            previous=currentnode;
            currentnode=currentnode->next;
          }
          tail=previous;
          previous->next=NULL;
          delete currentnode;
       }

       void linkedlist::display(){
          node *start;
          start=head;
          while(start!=NULL){
            cout<<start->data;
            cout<<' ';
            start=start->next;
          }
       }

int main()
{
    linkedlist ll;
    ll.insert_beg(10);
    ll.insert_beg(5);
    ll.display();
    cout<<endl;
    ll.insert_end(13);
    ll.insert_end(7);
    ll.display();
    ll.delete_beg(10);
    cout<<endl;
    ll.display();
    cout<<endl;
    ll.delete_end(7);
    cout<<endl;
    ll.display();
}
