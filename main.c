#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN     80

typedef struct link_node
{

char node_str[ MAX_STR_LEN ]; //Initializing the array of characters

struct link_node *next; //Pointing to the location of the next character

}link_node;

int compare_node(link_node *n1, link_node *n2 );
link_node *add_node(link_node *list, link_node *node );
void display_list( link_node *head );

void main()
{
    char userInput[MAX_STR_LEN];

    printf("Enter in strings followed by one blank string: \n");

    //first user entry
    link_node *headNode = NULL, *newNode;

    while (strlen(userInput) > 0)
    {
        gets(userInput);
        //create new node to compare to head node
        newNode = (link_node*)malloc(sizeof(link_node));
        newNode -> next = NULL;
        //make user string the string inside node newNode
        strcpy(newNode -> node_str, userInput);
        //compare the nodes and decide which one goes first
        headNode = add_node(headNode, newNode);
    }

    display_list(headNode);

}

// This function is used to compare two nodes.

// The return values are:

// -1: n1 < n2

//  0: n1 == n2

// +1: n1 > n2

int compare_node (link_node *n1, link_node *n2 ) //(head, newnode)
{
    if (strcmp((n1 -> node_str),(n2 -> node_str)) > 0) //n1 is later in the list than n2
    {
        return 1;
    }
    else if (strcmp((n1 -> node_str),(n2 -> node_str)) == 0) //same location in the list
    {
        return 0;
    }
    else if (strcmp((n1 -> node_str),(n2 -> node_str)) < 0) //n1 is first in the list than n2
    {
        return -1;
    }
}

// This function is used to add a new node into the
// alphabetically sorted linked list. The head of the
// list is pointed to by 'list'.
//
// The return value is the (possibly new) head pointer.

link_node *add_node(link_node *list, link_node *node ) //node is the new node
{
    link_node *temp1 = list; //create temp val to preserve the val of the head

    if (list == NULL) //if the list is empty
    {
        return node;
    }
    else if (compare_node(node, list) <= 0)
    {
        node -> next = list;
        list = node;
        return list;
    }
    else //if compare_node returns 0 or 1
    {
        link_node *temp2 = list;
        while ((temp1 != NULL)&&((compare_node(node, temp1)) == 1))
        {
            temp2 = temp1;
            temp1 = temp1 -> next;
        }

        node -> next = temp1;
        temp2 -> next = node;

        return list;
    }

}
void display_list(link_node *head )
{
    link_node *temp; //create temporary node that is at place of head

    while (head -> next != NULL)
    {
        printf("%s\n", head -> node_str);
        temp = head;
        head = head -> next;
    }

    printf("%s\n", head -> node_str);
}
