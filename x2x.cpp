#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

int theTime; //our clock // is equal to 1 sec //


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

        void choose_rad_possition(float &a,float &b,int D);
        void choose_rad_timelapse(int &timelapse);
        float move(float xt,float yt,float xa,float ya,float velocity);
        void caLculate_speeds(float &v1,float &v2,int xt,int yt,int xa,int ya,int ta,float tt);
        coordinates find_possition(float xa,float ya,float v1,float v2,int t,int ta);
        void choose_rad_speed(float &myvelocity);
};



void MyClass::choose_rad_possition(float &a,float &b,int D){
    a = (rand() % D) + 1;
    b = (rand() % D) + 1;
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

    node* getTail(){
        return tail;
    }

    
    node* getHead(){
        return head;
    }



    void display2(node *p)
    {
        //we start with the head
        
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






//--------------------//
 /* void FIND_CROWDED_PLACES(int size ,int days,node *myApointers[],int day,int x,int y, int xr, int yr,int Min_Duration ){

        cout<<"called crowed"<<endl;
        

        for(int i=0;i<size;i++)
        {
            for(int j=1;j<days;j++)
                {
                    cout<<"person "<<i<<"day "<<j+1<<"----->";
                    myApointers[i*days+j]=myApointers[i*days+j]->next;
                    node *p=myApointers[i*days+j];
                    while(p!=NULL && p->day==j+1)
                    {
                    cout <<  p->x << " " << p->y <<" " <<p->time<<" "<<p->hour << " "<<p->day<< "    ";    //print data
                    p = p->next;                //p takes value of the next node
                    }
                    cout<<endl;  
                }   
                
        }   

 }

  */


 void FIND_CROWDED_PLACES(int size ,int days,node *myApointers[],int day,int x,int y, int xr, int yr,int Min_Duration,Chain a[]){

        //Min_Duration in hours

        cout<<"called crowed"<<endl;

        int users[size];

        for (int c=0;c<size;c++){
            users[c]=0;
        }


        if(day==1){


            for(int i=0;i<size;i++){
                
                
                    cout<<"person "<<i<<" day "<<day<<"----->";
                    node *p=a[i].getHead();
                    node *p2=a[i].getHead();
                    while(p!=NULL && p->day==day && p2!=NULL && p2->day==day &&p2->next->day==day){
                    
                        p2 = p2->next;
                        cout <<  p->x << " " << p->y <<" " <<p->time<<" "<<p->hour << " "<<p->day<< "    ";             
                        cout <<  p2->x << " " << p2->y <<" " <<p2->time<<" "<<p2->hour << " "<<p2->day<< "    ";
                         
                        if(   ((p->x)>=x)&&(xr>=(p->x))  &&   ((p->y)>=y)&&(yr>=(p->y)) && ((p2->x)>=x)&&(xr>=(p2->x))  &&   ((p2->y)>=y)&&(yr>=(p2->y))){
                            cout<<"is in bounds"<<endl;
                            users[i] +=30; 

                        }
                        

                        cout<<"-----";

                        p = p->next; 

                    }
                    cout<<endl;  
                    
                    
            }  


        }


        else{
            for(int i=0;i<size;i++)
            {
                
                        cout<<"person "<<i<<"day "<<day<<"----->";
                        myApointers[i*days+day-1]=myApointers[i*days+day-1]->next;
                        node *p=myApointers[i*days+day-1];
                        node *p2=myApointers[i*days+day-1];
                       while(p!=NULL && p->day==day && p2!=NULL && p2->day==day &&p2->next->day==day){
                    
                        p2 = p2->next;
                        cout <<  p->x << " " << p->y <<" " <<p->time<<" "<<p->hour << " "<<p->day<< "    ";             
                        cout <<  p2->x << " " << p2->y <<" " <<p2->time<<" "<<p2->hour << " "<<p2->day<< "    ";
                         
                        if(   ((p->x)>=x)&&(xr>=(p->x))  &&   ((p->y)>=y)&&(yr>=(p->y)) && ((p2->x)>=x)&&(xr>=(p2->x))  &&   ((p2->y)>=y)&&(yr>=(p2->y))){
                            cout<<"is in bounds"<<endl;
                            users[i] +=30; 

                        }
                        

                        cout<<"-----";

                        p = p->next; 

                    }
                       
                       
                       
                       
                       
                       
                        /* while(p!=NULL && p->day==day)
                        {
                        cout <<  p->x << " " << p->y <<" " <<p->time<<" "<<p->hour << " "<<p->day<< "    ";    //print data
                        p = p->next;                //p takes value of the next node
                        } */
                        cout<<endl;  
                    
                    
            }  
        
        } 




//time in hours
//if node in the square add +30 secs
//calcl add answer


        int ans=0;

        for (int c=0;c<size;c++){
            cout<<users[c]<<endl;
            if ((users[c]/60)>=Min_Duration)
            ans+=1;


        }

        cout<<"People remained in this square are: "<< ans <<endl;

 
 }











int main(){
    srand((int)time(0));

    int size=5;

    int the_seconds=60;

    int the_hours=2;

    //int the_days=getInt(the_days);

    int the_days=3;

    int D=100;

    Chain people[size];
    
    theTime=0;
    
    MyClass myObj[size];
    
    node* mypointers[size][the_days];

    for (int i=0;i<size;i++){
        //cout<<"-----------------------person is---------    "<<i<<endl;
    myObj[i].choose_rad_possition(myObj[i].xs,myObj[i].ys,D);    // choose a random possition xs,ys to start
    myObj[i].choose_rad_timelapse(myObj[i].delay);    //choose time to wait
    //cout << myObj[i].xs << " " << myObj[i].ys << " " << myObj[i].delay << endl;

    myObj[i].ultimate_x=myObj[i].xs;
    myObj[i].ultimate_y=myObj[i].ys;

    data temp={myObj[i]. ultimate_x,myObj[i]. ultimate_y,theTime,0,1};
    people[i].add_node(temp);
    //cout << "My possition is : " <<myObj[i]. ultimate_x << " " << myObj[i].ultimate_y <<  endl;
    }


    node *dummy;

    for(int g=1;g<=the_days;g++){



        for(int u=0;u<=the_hours;u++){

            theTime=0;

            
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
                        myObj[i].choose_rad_possition(myObj[i].x,myObj[i].y,D);// choose a random possition x,y to go
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
                    data temp={myObj[i]. ultimate_x,myObj[i]. ultimate_y,theTime,u,g};
                    people[i].add_node(temp);
                    }


                }
            }


        }

        for(int s=0;s<size;s++){
            dummy=people[s].getTail();
            mypointers[s][g]=dummy;
        }

        


    }





    for (int k=0;k<size;k++){
        people[k].display();
    }
    

/* 
    // 2->day3
    for (int k=0;k<size;k++){
        people[k].display2( mypointers[k][2]);
    }
 */

cout<<"-------------------"<<endl;
  
for (int k=0;k<size;k++){
        people[k].display2( mypointers[k][2]);
    }



    node* myApointers[size*the_days];
  
    for (int q = 0; q<size; q++)
    {
        for (int t = 0; t<the_days; t++)
            {
                myApointers[q * the_days + t] = mypointers[q][t];
            }
    }
cout<<"-------------------"<<endl;

for (int k=0;k<size;k++){
        people[k].display2( myApointers[k*the_days+2]);
    }

cout<<"-------------------"<<endl;



FIND_CROWDED_PLACES(size,the_days,myApointers,2,20,20,60,60,1,people);
/////
    // people[0].display();

    // people[0].display2(dummy);

    // data temp={0,0,0,0,0};
    // people[0].add_node(temp);
    // people[0].add_node(temp);
    // people[0].add_node(temp);

    // people[0].display2(dummy);
////



//FIND_CROWDED_PLACES(size,the_days,mypointers,1,20,20,60,60,120);




    return 0;
}
