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
