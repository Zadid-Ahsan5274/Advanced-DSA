#include <iostream>

using namespace std;

class linkedlist{
    // defined a node type structure
    struct node{
     // node has data part and pointer parts for next node
     int data;
     node *next;
    };
    // node has head and tail parts
    node *head;
    node *tail;

public:
    linkedlist();  // constructor
    void insert_beg(int item);   // method for insert at beginning
    void insert_end(int item);   // method for insert at end
    int search(int item);   // method for search for an item
    void delete_beg();   // method for delete from beginning
    void delete_end();   // method for delete from end
    void display();    // method for display the list
};

// defining constructor - set head and tail values to NULL
linkedlist::linkedlist(){
head=NULL;
tail=NULL;
}

// implementation for insert at beginning method
void linkedlist::insert_beg(int item){
node *temp = new node;
temp->data=item;
temp->next=head;
if(head==NULL){
tail=temp;
}
head=temp;
}

// implementation for insert at end method
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

// implementation for search method
int linkedlist::search(int item){
  node *temp = new node;
  temp = head;
  int count = 0;
  do{
    if(temp->data==item){
      return count+1;
    }
    temp=temp->next;
    count++;
  } while(temp->next!=NULL);
  if(temp->next==NULL && temp->data==item){
    return count+1;
  }
  //if not found
  return -1;
}

// implementation for delete from beginning method
void linkedlist::delete_beg(){
node *temp=new node;
temp=head;
head=head->next;

delete temp;
}
// implementation for delete from end method
void linkedlist::delete_end(){
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

// implementation for display method
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
linkedlist ll;   // created an object for linkedlist class
ll.insert_beg(45);   // inserted 45 at beginning
ll.insert_beg(63);   // inserted 63 at beginning
ll.insert_end(3);    // inserted 3 at beginning
ll.insert_end(78);   // inserted 78 at beginning
ll.insert_end(97);   // inserted 97 at beginning
ll.display();     // displayed the list
cout<<endl;
int a = ll.search(78);    // search for an item - 100 and keep the return value in a variable, returns an index
if(a==-1){
  cout<<"Item not found in the list";   // if not found - return -1 that means item not found in the list
}
else{
  cout<<"Item found at position "<<a;   // if found - return the position or index - a
}
cout<<endl;
int b = ll.search(100);    // search for an item - 100 and keep the return value in a variable, returns an index
if(b==-1){
  cout<<"Item not found in the list";   // if not found - return -1 that means item not found in the list
}

else{
  cout<<"Item found at position "<<a;   // if found - return the position or index - a
}
ll.delete_beg();  // Deleted from end
cout<<endl;
ll.display();    // Displayed the list after deletion
cout<<endl;
ll.delete_end();   // Deleted from end
cout<<endl;
ll.display();    // Displayed the list after deletion
}
