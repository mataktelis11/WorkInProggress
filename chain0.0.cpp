#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isNumber(string s){
    for (int i=0;i<s.length();i++){
        if (isdigit(s[i]) == false)
            return false;
    }
    return true;
}

int getInt(int i){
    string s;
    while(true){
        cout << "Give me a possitive int" << endl;
        cin >> s;
        if (isNumber(s) == true){
            i = stoi(s);
            if (i>1){
                cout << i << endl;
                return i;
            }
            else {
                cout << "Not valid - Must be greater than 2" << endl;
            }
        }
        else{
            cout << "This is not an integer" << endl;
        }
    }
}

struct node
{
    int data;
    node *next;
};

class Chain
{
    //ever Chain consists of 2 pointers (of type node) 
    private:
        node *head; //points at the first node
        node *tail; //points at the last node
    public:
        //constuctor
        Chain()
        {
            //both pointers are NULL at first.This means the Chain is empty
            head = NULL; 
            tail = NULL;
        }
        //functions that adds a new node at the end of the Chain with data 'n'
        void add_node(int n)
        {
            //first create the node that will be added(appened) 
            node *p = new node;  //node has name 'p' and it is a pointer
            p->data = n;         //'p' has the given data
            p->next = NULL;      //next of node 'p' is GROUND(NULL) because the new node is at the end

            //we behave differently if the Chain is empty or not

            //empty Chain
            if(head == NULL)
            {
                //if the chain consists of one node then both head and tail point at that node!
                head = p;    //the haid points at the new node
                tail = p;    //the tail points at the new node
            }
            
            //non-empty Chain
            else
            {
                tail->next = p;      //'link' the new node ('p') with the tail node
                tail = tail->next;      //now we just make tail point at the last node which we just added
            }
        }


    //function that displayes the 'Chain'
    void display()
    {
        //we start with the head
        node *p=new node;
        p = head;
        //we stop when we find GROUND(NULL)
        while(p!=NULL)
        {
        cout << p->data << "\t";    //print data
        p = p->next;                //p takes value of the next node
        }
        cout<<endl;
    } 

    void insert(int index, int value)
    {
        
        if(0>=index) throw "invalid index!";
        
        node *pre=new node;
        node *cur=new node;
        node *p=new node;
        cur=head;
        for (int i = 1; i < index && cur!=NULL; i++){
            pre=cur;
            cur=cur->next;
        }
        if(cur==NULL) throw "invalid index!";
        
        if(index==1){
            node *temp=new node;
            temp->data=value;
            temp->next=head;
            head=temp;
        }
        else{
            //now we put 'p' between 'pre' and 'cur'
            pre->next=p;
            p->data=value;	
            p->next=cur;
            
        }
    }

    void delete_first()
  {
    node *p=new node;   //
    p=head;             //
    head=head->next;    //
    delete p;           //
  }

  void delete_last()
  {
    node *current=new node;
    node *previous=new node;
    current=head;
    while(current->next!=NULL)
    {
      previous=current;
      current=current->next;	
    }
    tail=previous;
    previous->next=NULL;
    delete current;
  }

  void delete_position(int pos)
  {
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
  }

};


void move(Chain person,int clock,int velocity){

    int x;
    x=velocity*clock;
    cout<<x<<endl;

}


int main(){
    /* 
    int i = getInt(i);

    srand((int)time(0));
    int r = (rand() % (i-1)) + 1;
	cout << r << " " << i-r << endl;
 */
    /* Chain a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.display(); */
    /* try{
        a.insert(4,5);
    } catch(const char* message){
        cerr << message << endl;
    }
    
    a.display(); */
/* 
    int size=10;

    Chain people[size];
    
    for(int i=0;i<=3600;i+=30){
        for (int j=0;j<size;j++){
            people[j].add_node(i);
        }
    }
    for (int j=0;j<size;j++){
            people[j].display();
    }
 */

/* 
Chain a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.display();

 */

int size=10;

    Chain people[size];


    for (int i=0;i<=120;i+=30){
        for (int j=0;j<size;j++)
        move(people[0],i,1);
        
    }

    return 0;
}