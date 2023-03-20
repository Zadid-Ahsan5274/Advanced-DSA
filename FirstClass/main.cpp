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
