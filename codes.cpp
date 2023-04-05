// Implementation of sortedtype array
// -----------------------------------------
// sortedtype.h
#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED
#include <iostream>
using namespace std;
const int MAX_ITEMS = 5;
template <class ItemType>
class SortedType
{
 public :
 SortedType();
 void MakeEmpty();
 bool IsFull();
 int LengthIs();
 void InsertItem(ItemType);
 void DeleteItem(ItemType);
 void RetrieveItem(ItemType&, bool&);
 void ResetList();
 void GetNextItem(ItemType&);
 //private:
 int length;
 int info[MAX_ITEMS];
 int currentPos;
 //void view();

 void view(){
   //arr[10];
   for(int i = 0; i <5;i++){
    cout<<info[i]<<" ";
   }
}

/*void SortedType<ItemType>::DeleteItem(ItemType
item)
{
 int location = 0;
 while (item != info[location])
 location++;
 for (int index = location + 1; index < length;
index++)
 info[index - 1] = info[index];
 length--;
}
*/
/*void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
 int midPoint, first = 0, last = length - 1;
 bool moreToSearch = (first <= last);
 found = false;
 while (moreToSearch && !found)
 {
 midPoint = (first + last) / 2;
 if(item < info[midPoint])
 {
 last = midPoint - 1;
 moreToSearch = (first <= last);
 }
 else if(item > info[midPoint])
 {
 first = midPoint + 1;
 moreToSearch = (first <= last);
 }
 else
 {
 found = true;
 item = info[midPoint];
 }
 }
}*/

int searchItem(int n){
    int left = 0;
    int right = 5;
    int middle = (left+right)/2;
    while(left <= right){
        if(info[middle]==n){
            return middle;
        }
        else if(info[middle] > n){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }
    return -1;
}
};
#endif // SORTEDTYPE_H_INCLUDED

// sortedtype.cpp
#include "sortedtype.h"
#include <iostream>
using namespace std;

template <class ItemType>
SortedType<ItemType>::SortedType()
{
 length = 0;
 currentPos = - 1;
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
 length = 0;
}
template <class ItemType>
bool SortedType<ItemType>::IsFull()
{
 return (length == MAX_ITEMS);
}
template <class ItemType>
int SortedType<ItemType>::LengthIs()
{
 return length;
}
template <class ItemType>
void SortedType<ItemType>::ResetList()
{
 currentPos = - 1;
}
template <class ItemType>
void
SortedType<ItemType>::GetNextItem(ItemType&
item)
{
 currentPos++;
 item = info [currentPos];
}
template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType
item)
{
 int location = 0;
 bool moreToSearch = (location < length);
 while (moreToSearch)
 {
 if(item > info[location])
 {
 location++;
 moreToSearch = (location < length);
 }
 else if(item < info[location])
 moreToSearch = false;
 }
 for (int index = length; index > location;
index--)
 info[index] = info[index - 1];
 info[location] = item;
 length++;
}
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType
item)
{
 int location = 0;
 while (item != info[location])
 location++;
 for (int index = location + 1; index < length;
index++)
 info[index - 1] = info[index];
 length--;
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType&
item, bool& found)
{
 int midPoint, first = 0, last = length - 1;
 bool moreToSearch = (first <= last);
 found = false;
 while (moreToSearch && !found)
 {
 midPoint = (first + last) / 2;
 if(item < info[midPoint])
 {
 last = midPoint - 1;
 moreToSearch = (first <= last);
 }
 else if(item > info[midPoint])
 {
 first = midPoint + 1;
 moreToSearch = (first <= last);
 }
 else
 {
 found = true;
 item = info[midPoint];
 }
 }
}
//template <class ItemType>
/*void View(int arr[5]){
   //arr[10];
   for(int i = 0; i <5;i++){
    cout<<arr[i];
   }
}*/

// main.cpp
#include <iostream>
#include "sortedtype.h"
#include "sortedtype.cpp"
using namespace std;

int main()
{
    SortedType<int> st;
    //int info[5];
    st.InsertItem(1);
    st.InsertItem(5);
     st.InsertItem(8);
     st.InsertItem(10);
     st.InsertItem(4);
     //st.InsertItem(7);

     st.view();
     //st.RetrieveItem(7,false);
     cout<<st.searchItem(10);

}

// Implementation of linkedlist
// -----------------------------------------
// linkedlist.h
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

class linkedlist()
{

};
#endif // LINKEDLIST_H_INCLUDED

// linkedlist.cpp
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

// main.cpp

// Another correct Implementation of linkedlist
// -----------------------------------------
// linkedlist.cpp
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
