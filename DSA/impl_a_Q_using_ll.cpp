#include<iostream>
using namespace std;

struct node{
    int num;
    struct node * next= NULL;
};

class Q{
    private:
    struct node * front=NULL;
    struct node * rear=NULL;

    public:
    void enque(int n)
    {   struct node * temp = new node;
        temp->num = n;
        if(rear!=NULL)
        {

            rear->next = temp;
        }
        else{
            front=temp;
        }
        rear = temp;
        return;
    }
    int dequeue(){

        if(front == rear && front == NULL)
        {
            cout<<"underflow"<<endl;
            return -999;

        }
        else
        {
            struct node * temp = front;
            int k = temp->num;
            front = front->next;
            free(temp);
            return k;
            
        }
    } 
};

int main()
{
    Q first,second;
    int t=0;

    while(t!=-1)
    {
        cout<<"enter -1 to close;"<<endl;
        cout<<"  1 to push;"<<endl;
        cout<<"  2 to pop; "<<endl;
        cin>>t;
        if(t==1)
        {
            cout<<"enter number:"<<endl;
            int n;
            cin>>n;
            second.enque(n);
        }
        else if(t==2)
        {
            cout<<(second.dequeue())<<endl;
        }
    }
    return 0;
}
