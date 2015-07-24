#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
// Node Declaration
struct node
{
	int priority;
	int info;
	struct node *link;
};
// Class Priority Queue
class Priority_Queue
{
    private:
        node *front;
    public:
        Priority_Queue()
        {
            front = NULL;
        }
        /*
         * Insert into Priority Queue
         */
        void insert(int item, int priority)
        {
            node *tmp, *q;
            tmp = new node;
            tmp->info = item;
            tmp->priority = priority;
            if (front == NULL || priority < front->priority)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {
                q = front;
                while (q->link != NULL && q->link->priority <= priority)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
        }
        /*
         * Delete from Priority Queue
         */
        void del()
        {
            node *tmp;
            if(front == NULL)
                cout<<"Queue Underflow\n";
            else
            {
                tmp = front;
                cout<<"Deleted item is: "<<tmp->info<<endl;
                front = front->link;
                free(tmp);
            }
        }
        /*
         * Print Priority Queue
         */
        void display()
        {
            node *ptr;
            ptr = front;
            if (front == NULL)
                cout<<"Queue is empty\n";
            else
            {	cout<<"Queue is :\n";
                cout<<"Priority       Item\n";
                while(ptr != NULL)
                {
                    cout<<ptr->priority<<"                 "<<ptr->info<<endl;
                    ptr = ptr->link;
                }
            }
        }
};
/*
 * Main
 */
int main()
{
    int choice, item, priority;
    Priority_Queue pq; 
    while(1)
    {
    	cout<<"\n==========================================================";
		cout<<"\n   Basic Priority Operations implemented on linked list : ";
		cout<<"\n==========================================================\n";
        cout<<"1.Insert Element in a Priority Queue..\n";
        cout<<"2.Delete Element of the Priority Queue..\n";
        cout<<"3.Display Element of the Priority Queue..\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : "; 
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>item;
            cout<<"Enter its priority : ";
            cin>>priority;
            pq.insert(item, priority);
            break;
        case 2:
            pq.del();
            break;
        case 3:
            pq.display();
            break;
        case 4:
        	cout<<"\n Thanks for using..";
            exit(0);
        default :
            cout<<"Wrong choice : Try again..\n";
        }
    }
    return 0;
}
