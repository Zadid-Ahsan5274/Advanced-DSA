// C++ Program to implement preorder traversal of binary tree using stack
#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
    Node(char ele)
    {
        data = ele;
        left = NULL;
        right = NULL;
    }
};

/* Function to implement Preorder Traversal */
void preorder(Node *root)
{
    /* Check Base Condition */
    if(root == NULL)
    return;

    /* Create an Empty Stack */
    stack <Node *> st;

    /* Push root Node into it */
    st.push(root);

    while(!st.empty())
    {
        /* Pop and print top node */
        Node *temp = st.top();
        st.pop();
        cout<<temp -> data<<" ";

        /* Push Right Child, if exists */
        if(temp -> right)
        st.push(temp -> right);

        /* Push Left Child, if exists */
        if(temp -> left)
        st.push(temp -> left);
    }
}
int main()
{
    /* Creating a Binary tree and inserting some nodes in it */
    Node *root = NULL;

    root = new Node('A');
    root -> left = new Node('B');
    root -> right = new Node('C');
    root -> left -> left = new Node('D');
    root -> left -> right = new Node('E');
    root -> left -> left -> right = new Node('H');
    root -> right -> left = new Node('F');
    root -> right -> right = new Node ('G');
    root -> right -> left -> left = new Node('I');
    root -> right -> left -> right = new Node('J');

    /* Calling function to perform preorder traversal*/
    cout<<"The Pre-order Traversal of the Given Binary Tree is: ";
    preorder(root);
}
