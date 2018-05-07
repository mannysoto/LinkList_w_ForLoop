#include <iostream>

using namespace std;

typedef struct myNode {
    int intData;
    struct myNode* nextNode;
} myNodeType;

int main()
{

    //Create an empty node to use as the head node.
    myNodeType* headNode = NULL;
    //Create an empty node to use as the new tail node, which will need its nextNode to NULL after the last node is deleted.
    myNodeType* tailNode = NULL;
    //Create an empty node to use for iterating through the list.
    myNodeType* current = NULL;
    //Previous node
    myNodeType* previous = NULL;

    int userData = 0;
    int intDeleteNode = -1;
    int intEndProgram = -1;

    do{
        for(int i=0;i<5;i++){
            cout << "Enter an integer: " << endl;
            //cin >> userData;
            userData = i;
            cout << "\tYou entered: " << userData << endl;
            current = (myNodeType*)malloc(sizeof(myNodeType));
            current->intData = userData;
            current->nextNode = NULL;

            if(i==0) headNode = current;
            if(i!=0)previous->nextNode=current;
            tailNode = current;
            previous = current;
            current = NULL;

        }
        system("cls");

        cout << "------------------------------------------" << endl;
        //Create an empty node to use for iterating through the list.
        //Set the iteration to begin at the first node that was created.
        current = headNode;
        while(current != NULL){
            cout << '\t' << "Address: " << current << endl;
            cout << "\t\t" << "Data: " << current->intData << endl;
            cout << "\t\t\t" << "Next Node Address: " << current->nextNode << endl;
            current = current->nextNode;
        }
        //system("cls");

        cout << "------------------------------------------" << endl;
        //Iterate through the nodes from start to finish asking the user if you want to keep the node.
        current = headNode;
        while(current != NULL){
            cout << '\t' << "Address: " << current << endl;
            cout << "\t\t" << "Data: " << current->intData << endl;
            cout << "\t\t\t" << "Next Node Address: " << current->nextNode << endl;
            //current = current->nextNode;
            cout << "Keep node?" << endl;
            cout << "\tEnter 0 to delete. Any other integer to keep: ";
            cin >> intDeleteNode;
            if(intDeleteNode == 0){
                if (current == headNode){
                  headNode = current->nextNode;
                  free(current);
                  current = headNode;
                }
                else if (current == tailNode) {
                    tailNode = previous;
                    tailNode->nextNode = NULL;
                    free(current);
                    current = NULL;
                }
                else{
                    previous->nextNode = current->nextNode;
                    free(current);
                    current = previous->nextNode ;
                    cout << "Case between head and tail not programmed yet." << endl;
                }
                if(intDeleteNode != 0) previous = current;
            }
            else{
                if(intDeleteNode != 0) previous = current;
                current = current->nextNode;
            }
        }

        cout << "------------------------------------------" << endl;
        //Create an empty node to use for iterating through the list.
        //Set the iteration to begin at the first node that was created.
        current = headNode;
        while(current != NULL){
            cout << '\t' << "Address: " << current << endl;
            cout << "\t\t" << "Data: " << current->intData << endl;
            cout << "\t\t\t" << "Next Node Address: " << current->nextNode << endl;
            current = current->nextNode;
        }

        //Free remaining memory.
        current = headNode;
        while(current != NULL){
          headNode = current->nextNode;
          free(current);
          current = headNode;
        }

        //sentinel
        cout << "End program?" << endl;
        cout << "\tEnter 0 to end. Any other integer to continue: ";
        cin >> intEndProgram;
        system("cls");

    }while(intEndProgram != 0);

    return 0;
}
