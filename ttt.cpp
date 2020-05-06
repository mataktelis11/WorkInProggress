#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

int theTime; //our clock // is equal to 1 sec //

struct coordinates{
    float xi;
    float yi;
};

class MyClass {      
  public:             
        float xs;
        float ys;
        float x;
        float y;
        float v;
        int sec;
        int delay;
        float Vx;
        float Vy;
        int moveTime=0;
        int started_moving;
        float ultimate_x;
        float ultimate_y;

        void choose_rad_possition(float &a,float &b);
        void choose_rad_timelapse(int &timelapse);
        float move(float xt,float yt,float xa,float ya,float velocity);
        void caLculate_speeds(float &v1,float &v2,int xt,int yt,int xa,int ya,int ta,float tt);
        coordinates find_possition(float xa,float ya,float v1,float v2,int t,int ta);
        void choose_rad_speed(float &myvelocity);
};



void MyClass::choose_rad_possition(float &a,float &b){
    a = (rand() % 100) + 1;
    b = (rand() % 100) + 1;
}

void MyClass::choose_rad_timelapse(int &timelapse){
    timelapse = (rand() % 20) + 1;
    timelapse +=2;
    timelapse += theTime;
}
float MyClass::move(float xt,float yt,float xa,float ya,float velocity){
    
    float divVelocity = (float)velocity;
    int temp1 = (xt - xa)*(xt - xa) + (yt - ya)*(yt - ya) ; //Dt = apostasi shmeiwn/metro taxititas
    float temp2 = (float)temp1;
    temp2 = sqrt (temp2);

    return temp2 / divVelocity ;
}

//find Vx and Vy
void MyClass::caLculate_speeds(float &v1,float &v2,int xt,int yt,int xa,int ya,int ta,float tt){
    v1 = (xt - xa)/(tt - ta);
    v2 = (yt - ya)/(tt - ta);
}
//calculate every sec
coordinates MyClass::find_possition(float xa,float ya,float v1,float v2,int t,int ta){

    float xix = xa + v1*(t-ta);
    float yiy = ya + v2*(t-ta);

   // cout << xa << " " << v1 << " " << t-ta << " " << v1*(t-ta) << " " << xa + v1*(t-ta)<< endl;
    coordinates xy={xix,yiy};
    return xy;
}
void MyClass::choose_rad_speed(float &myvelocity){

    int i = (rand() % 9) + 1;
    i+=7;
    //cout<<i<<endl;
    float div = (float)i;
    myvelocity = div/10;
}






struct data
{
    float x;
    float y;
    int time;
    int hour;
    int day;
};
struct node
{
    float x;
    float y;
    int time;
    int day;
    int hour;
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
        void add_node(data d)
        {


            //cout<<"add_node was called"<<endl;
            float pos = d.x;
            float hpos = d.y;
            int secs= d.time;
            int hours = d.hour;
            int days= d.day;
            //first create the node that will be added(appened) 
            node *p = new node;  //node has name 'p' and it is a pointer
            
        
            p->x = pos;         //'p' has the given data
            p->y = hpos; 
            p->time = secs;
            p->hour = hours;
            p->day =  days;
             
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
        cout <<"->";
        while(p!=NULL)
        {
        cout <<  p->x << " " << p->y <<" " <<p->time<<" "<<p->hour << " "<<p->day<< "    ";    //print data
        p = p->next;                //p takes value of the next node
        }
        cout<<endl;
    } 


};










int main(){
    srand((int)time(0));

    int size=5;

    int the_seconds=60;

    Chain people[size];
    
    theTime=0;
    
    MyClass myObj[size];
    



    for (int i=0;i<size;i++){
        //cout<<"-----------------------person is---------    "<<i<<endl;
    myObj[i].choose_rad_possition(myObj[i].xs,myObj[i].ys);    // choose a random possition xs,ys to start
    myObj[i].choose_rad_timelapse(myObj[i].delay);    //choose time to wait
    //cout << myObj[i].xs << " " << myObj[i].ys << " " << myObj[i].delay << endl;

    myObj[i].ultimate_x=myObj[i].xs;
    myObj[i].ultimate_y=myObj[i].ys;

    data temp={myObj[i]. ultimate_x,myObj[i]. ultimate_y,theTime,0,1};
    people[i].add_node(temp);
    //cout << "My possition is : " <<myObj[i]. ultimate_x << " " << myObj[i].ultimate_y <<  endl;
    }

    
    while(theTime<the_seconds){
        theTime+=1;
        
        for (int i=0;i<size;i++){
            
            if(theTime<myObj[i].sec && theTime>myObj[i].delay){
                //cout << "i am moving now" << endl;
                coordinates xy = myObj[i].find_possition(myObj[i].xs,myObj[i].ys,myObj[i].Vx,myObj[i].Vy,theTime,myObj[i].started_moving);
                //cout << xs << " " << ys << " " << Vx << " " << Vy << " " << theTime<< " " << sec << endl;
                //cout<<xy.xi<<" "<<xy.yi<<endl;
                myObj[i].ultimate_x=xy.xi;
                myObj[i].ultimate_y=xy.yi;

            }
            
            else if(theTime==myObj[i].sec){
                //reached the possition / start waiting //
                //cout<<"i reached the possition"<<endl;
                myObj[i].choose_rad_timelapse(myObj[i].delay);
                myObj[i].xs=myObj[i].x;
                myObj[i].ys=myObj[i].y;
                //cout << myObj[i].xs << " " << myObj[i].ys << " " << myObj[i].delay << endl;

                myObj[i].ultimate_x=myObj[i].xs;
                myObj[i].ultimate_y=myObj[i].ys;

            }

            else {

                //cout << "i will start moving now" << endl;
                myObj[i].choose_rad_possition(myObj[i].x,myObj[i].y);// choose a random possition x,y to go
                //cout << "i will go at " << myObj[i].x << " " << myObj[i].y << " "  << endl;
                myObj[i].choose_rad_speed(myObj[i].v);//choose a random speed
            // cout << "with speed " << myObj[i].v << endl;
                myObj[i].sec=myObj[i].move(myObj[i].x,myObj[i].y,myObj[i].xs,myObj[i].ys,myObj[i].v);//find dt
                //cout <<"it will take me "<< myObj[i].sec << endl;
                myObj[i].sec+=theTime;
                myObj[i].started_moving = theTime; //save the time you start moving
                myObj[i].caLculate_speeds(myObj[i].Vx,myObj[i].Vy,myObj[i].x,myObj[i].y,myObj[i].xs,myObj[i].ys,theTime,myObj[i].sec); //find Vx, Vy
                //cout <<"speeds: "<< myObj[i].Vx << " " << myObj[i].Vy << " "  << endl;
            }

            //cout << "My possition is : " <<myObj[i]. ultimate_x << " " << myObj[i].ultimate_y <<  endl;


            if((theTime % 30) == 0){
            data temp={myObj[i]. ultimate_x,myObj[i]. ultimate_y,theTime,0,1};
            people[i].add_node(temp);
            }


        }
    }








    for (int k=0;k<size;k++){
        people[k].display();
    }



    //choose_rad_speed(v);

    //cout << x0 << " " << y0 << " " << v << endl;

    return 0;
}
