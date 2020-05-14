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

class Move {      
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



void Move::choose_rad_possition(float &a,float &b,int D){
    a = (rand() % D) + 1;
    b = (rand() % D) + 1;
}

void Move::choose_rad_timelapse(int &timelapse){
    timelapse = (rand() % 20) + 1;
    timelapse +=2;
    timelapse += theTime;
}
float Move::move(float xt,float yt,float xa,float ya,float velocity){
    
    float divVelocity = (float)velocity;
    int temp1 = (xt - xa)*(xt - xa) + (yt - ya)*(yt - ya) ; //Dt = apostasi shmeiwn/metro taxititas
    float temp2 = (float)temp1;
    temp2 = sqrt (temp2);

    return temp2 / divVelocity ;
}

//find Vx and Vy
void Move::caLculate_speeds(float &v1,float &v2,int xt,int yt,int xa,int ya,int ta,float tt){
    v1 = (xt - xa)/(tt - ta);
    v2 = (yt - ya)/(tt - ta);
}
//calculate every sec
coordinates Move::find_possition(float xa,float ya,float v1,float v2,int t,int ta){

    float xix = xa + v1*(t-ta);
    float yiy = ya + v2*(t-ta);

   // cout << xa << " " << v1 << " " << t-ta << " " << v1*(t-ta) << " " << xa + v1*(t-ta)<< endl;
    coordinates xy={xix,yiy};
    return xy;
}
void Move::choose_rad_speed(float &myvelocity){

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
        cout <<"--ppp->";
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




	void length(){
		node *p=new node;
        p = head;
		int i=1;			//initialize counter
		while(p!=NULL)
        {
			i+=1;			//counter increases
			p = p->next;    //p takes value of the next node
        }
		cout<<"length is "<<i<<endl;
	}



    void insert(int index, data d)
    {
        float pos = d.x;
        float hpos = d.y;
        int secs= d.time;
        int hours = d.hour;
        int days= d.day;
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
            
            temp->x = pos;         //'p' has the given data
            temp->y = hpos; 
            temp->time = secs;
            temp->hour = hours;
            temp->day =  days;

            temp->next=head;
            head=temp;
        }
        else{
            //now we put 'p' between 'pre' and 'cur'
            pre->next=p;
            node *temp=new node;
            
            temp->x = pos;         
            temp->y = hpos; 
            temp->time = secs;
            temp->hour = hours;
            temp->day =  days;

            p->x = pos;         //'p' has the given data
            p->y = hpos; 
            p->time = secs;
            p->hour = hours;
            p->day =  days;
            
            p->next=cur;
            
        }
    }



    void delete_node(int index){

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

            node *p=new node;   //
            p=head;             //
            head=head->next;    //
            delete p;           //
        }

        else{

            pre->next=cur->next;




       }




    }



    //overload
    void delete_node(node *p){

         node *pi=new node;

        pi=p->next;

        //cout<<p->x<<"   "<<pi->x;

        p->next=pi->next;

    }


    //overload
    node* insert(node *p,node *in){


        node *nextnode = p->next;

        p->next = in;

        in->next=nextnode;

        return in;

    }

    //alternative delete:delete the given node
    void deleteNode(node *node_ptr)  
    {  
        node *temp = node_ptr->next;  
        node_ptr->x = temp->x;  
        node_ptr->y = temp->y; 
        node_ptr->time = temp->time; 
        node_ptr->day = temp->day; 
        node_ptr->hour = temp->hour; 
    
        node_ptr->next = temp->next;  
        free(temp);  
    }  



};





 void FIND_CROWDED_PLACES(int size ,int days,node *myApointers[],int day,int x,int y, int xr, int yr,int Min_Duration,Chain a[]){


         //cout<<"called crowed"<<endl;

         int users[size];

        for (int c=0;c<size;c++){
             users[c]=0;
        }

        for(int i=0;i<size;i++){
            //cout<<"person "<<i<<" day "<<day<<"----->";

            
            node *user =myApointers[(i) * days + day];
            //a[i].display2(user);

            node *fast=user->next;
            node *slow=user;
            while(fast!=NULL  && slow!=NULL){

                        
            if(   ((slow->x)>=x)&&(xr>=(slow->x))  &&   ((slow->y)>=y)&&(yr>=(slow->y)) && ((fast->x)>=x)&&(xr>=(fast->x))  &&   ((fast->y)>=y)&&(yr>=(fast->y))){
                //cout<<"is in bounds"<<endl;
                users[i] +=30; 
            }              
            fast=fast->next;
            slow=slow->next; 
            }

        }


        int ans=0;

        for (int c=0;c<size;c++){
            //cout<<users[c]<<endl;
            if ((users[c]/3600)>=Min_Duration)
            ans+=1;
        }

        cout<<"People remained in this square are: "<< ans <<endl;



 
 }





//User Trajectory, Day, List of COVID-19 patients    --  t1 and t2 in secs

bool POSSIBLE_COVID_19_INFECTION(Chain person,int theDay ,int patients,Chain people[],int size ,int t1,int t2,int r,node *myApointers[],int alldays,int index){
    //cout<<"day is:"<<theDay<<" ";
    //person.display2(myApointers[(index) * alldays + theDay]);

    for(int y=size;y>size-patients;y--){
                
                //cout<<y-1<<endl;
                //people[y-1].display2(myApointers[(y-1) * alldays + theDay]);
                //take time and x,y of patient
                //then monitor the trajectory of the person for this cycle
                node *p = myApointers[(y-1) * alldays + theDay];


               // cout<<p->x<<" ";
               // cout<<p->y<<" ";
                while(p!=NULL){

                     float cycl_x = p -> x;
                     float cycl_y = p -> y;

                     int take_secs = p->time;
                     int take_hour = p->hour;

                     take_secs +=take_hour*3600 ;

                     int secs_end_of_covid = take_secs + t2*3600;

                    // cout<<cycl_x<<" ";

                     int counter=0;

                    //take trajectory of user

                    node *user =myApointers[(index) * alldays + theDay];
                    //person.display2(user);

                    node *fast=user->next;
                    node *slow=user;
                    while(fast!=NULL  && slow!=NULL){

                       // cout<<"-"<<slow->x<<" "<<slow->y<<" "<<fast->x<<" "<<fast->y<<"-    ";


                         
                         if(     (  (sqrt( (slow->x - cycl_x)*(slow->x - cycl_x) + (slow->y - cycl_y)*(slow->y - cycl_y) ) )<= r   ) && ( (sqrt( (fast->x - cycl_x)*(fast->x - cycl_x) + (fast->y - cycl_y)*(fast->y - cycl_y) ) )<= r )     ) {
                             //cout<<"is in bounds"<<endl;
                            if( (user->time + (user->hour)*3600 ) <= secs_end_of_covid )
                                         counter +=30; 


                         }
    


                                        
                        fast=fast->next;
                        slow=slow->next; 


                    }
                    //cout<<counter<<endl;
                 if (counter >=100 ){
                     //cout<<"person of index: "<<index<<" may be infected on day: "<<theDay;
                     return true;
                 		}


                     p=p->next;
                }
               // cout<<endl;
    }

	return false;     

}



//g,,,k,size
//people[k],g,size,myApointers,


void CREATE_GAPS(int day,Chain person,node* myApointers[],int index,int all_days){


    node *p = new node;
	//p = myApointers[index * all_days + day];

    person.display2(myApointers[index * all_days + day]);

        // while(p->next->next!=NULL){
            
            // p=p->next;
           
        // int t = (rand() % 2) + 1;
           // if(t==1 && p->next->next!=NULL){
              //cout<<"e";
               // person.delete_node(p);
           // }
            

    
        // }

       // person.display2(p);

}

void CREATE_GAPS2(Chain person,int theDay ,int size,node *myApointers[],int alldays,int index){
	node *user =myApointers[(index) * alldays + theDay];
	//person.display2(user);
	
        while(user->next->next!=NULL){
            
            user=user->next;
           
        int t = (rand() % 2) + 1;
           if(t==1 && user->next->next!=NULL){
              cout<<"e";
               person.delete_node(user);
           }
            

    
        }
	
	
	
	
	
	
	
	
}	

void REPAIR(int day,Chain person,node* myApointers[],int index,int all_days){






        node *fast = myApointers[index*all_days + day]->next;
        node *slow = myApointers[index*all_days + day];
        //cout<<"------repairing:";
        while(fast!=NULL &&  slow!=NULL){

           int t1=slow->time + (slow->hour)*60;
           int t2=fast->time + (fast->hour)*60;

           //cout<<t1<<" "<<t2<<" "<<t2-t1<<" "<<slow->time<<" "<<slow->hour<<" "<<fast->time<<" "<<fast->hour<<" "<<" "<<fast->day<<" "<<fast->day<<endl;

           if((t2-t1)!=30 ){
                //cout<<"gap"<<endl;
                node *mydummy=new node ;
                   

        

                    float d = sqrt( (slow->x - fast->x)*(slow->x - fast->x)  +  (slow->y - fast->y)*(slow->y - fast->y) );
                    float speed=d/(t2-t1);
                    float speedx = ( fast->x - slow->x )/(t2-t1);
                    float speedy = ( fast->y - slow->y )/(t2-t1);

                    float xa,ya,x,y;

                    xa=slow->x;
                    ya=slow->y;
                    x = xa + speedx*30;
                    y = ya + speedy*30;

                    mydummy->x=x;
                    mydummy->y=y;
                    mydummy->day=slow->day;

                    int t,hour;
                    if(slow->time == 60){
                        t=30;
                        hour=slow->hour+1;
                    }
                    else{
                        t=slow->time+30;
                        hour=slow->hour;

                    }


                    mydummy->time=t;
                    mydummy->hour=hour;
                    
                    slow=person.insert(slow,mydummy);


                


           }


            fast=fast->next;
            slow=slow->next; 

        }






}



void REPAIR2(Chain person,int theDay ,int size,node *myApointers[],int alldays,int index){
	node *user =myApointers[(index) * alldays + theDay];
	//person.display2(user);
	
	

        node *fast = user->next;
        node *slow =user;
        //cout<<"------repairing:";
        while(fast!=NULL &&  slow!=NULL){

           int t1=slow->time + (slow->hour)*3600;
           int t2=fast->time + (fast->hour)*3600;

           //cout<<t1<<" "<<t2<<" "<<t2-t1<<" "<<slow->time<<" "<<slow->hour<<" "<<fast->time<<" "<<fast->hour<<" "<<" "<<fast->day<<" "<<fast->day<<endl;

			//cout<<"slow:"<<slow->x<<" "<<slow->y<<" fast:"<<fast->x<<" "<<fast->y<<"  ";
			//cout<<t1<<" "<<t2<<" "<<t2-t1<<" --- ";
			cout<<t2-t1<<" --- ";
			
           if((t2-t1)!=30 ){
                cout<<"gap"<<endl;
                node *mydummy=new node ;
                  
                    float d = sqrt( (slow->x - fast->x)*(slow->x - fast->x)  +  (slow->y - fast->y)*(slow->y - fast->y) );
                    float speed=d/(t2-t1);
                    float speedx = ( fast->x - slow->x )/(t2-t1);
                    float speedy = ( fast->y - slow->y )/(t2-t1);

                    float xa,ya,x,y;

                    xa=slow->x;
                    ya=slow->y;
                    x = xa + speedx*30;
                    y = ya + speedy*30;

                    mydummy->x=x;
                    mydummy->y=y;
                    mydummy->day=slow->day;

                    int t,hour;
                    if(slow->time == 3600){
                        t=30;
                        hour=slow->hour+1;
                    }
                    else{
                        t=slow->time+30;
                        hour=slow->hour;

                    }


                    mydummy->time=t;
                    mydummy->hour=hour;
                    
                    slow=person.insert(slow,mydummy);


                


           }


            fast=fast->next;
            slow=slow->next; 

        }


		cout<<endl;
	
	
	
}


void SUMMARIZE_TRAJECTORY(int day,int days_before, Chain person,int r,node* myApointers[],int index,int all_days){
    cout<<"called this";
    node *p = myApointers[index*all_days + day]->next;

   // person.display2(p);
    float x = p->x;
    float y = p->y;

        while(p!=NULL){
            cout<<p->x<<" "<<p->y<<" ";
           
           float d = sqrt( (p->x - x)*(p->x - x)  +  (p->y - y)*(p->y - y) );
           if (d<80 && p->next!=NULL){cout<<" del ";
            person.deleteNode(p);
           }
           
            p=p->next;
            

    
        }
    
    cout<<"ended";
}





int main(){
    srand((int)time(0));

    int size=10;

    int the_seconds=3600;

    int the_hours=2;

    //int the_days=getInt(the_days);

    int the_days=5;

    int D=100;

    int infected=4; //infected are the last 2

    Chain people[size];
    
    theTime=0;
    
    Move myObj[size];
    
    node* mypointers[size][the_days+1];
    
    node* myApointers[size*(the_days+1)];

    node *dummy = new node;

    for (int i=0;i<size;i++){
			//cout<<"-----------------------person is---------    "<<i<<endl;
		myObj[i].choose_rad_possition(myObj[i].xs,myObj[i].ys,D);    // choose a random possition xs,ys to start
		myObj[i].choose_rad_timelapse(myObj[i].delay);    //choose time to wait
		//cout << myObj[i].xs << " " << myObj[i].ys << " " << myObj[i].delay << endl;

		myObj[i].ultimate_x=myObj[i].xs;
		myObj[i].ultimate_y=myObj[i].ys;

		data temp={myObj[i]. ultimate_x,myObj[i]. ultimate_y,theTime,0,1};
		people[i].add_node(temp);
		dummy=people[i].getTail();
							 
		//people[i].display2(dummy);
		//cout<<i<<" ";
		mypointers[i][1]=dummy;
		//cout << "My possition is : " <<myObj[i]. ultimate_x << " " << myObj[i].ultimate_y <<  endl;
    }


    

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
                     if(u==0 && theTime==30 &&g!=1){
                         
                         dummy=people[i].getTail();
                         //cout<<i<<" "<<g<<" ";
                         //people[i].display2(dummy);
                         mypointers[i][g]=dummy;
                     }
                    }


                }
            }


        }

        // for(int s=0;s<size;s++){
        //     dummy=people[s].getTail();
        //     mypointers[s][g]=dummy;
        // }




        //node* myApointers[size*the_days];
 




for (int q = 0; q<size; q++)
    {
        for (int t = 1; t<the_days+1; t++)
            {
                myApointers[q * (the_days) + t] = mypointers[q][t];
            }
    }




for (int k=0;k<size;k++){

	// people[k].display2(myApointers[k * the_days + g]);
   // CREATE_GAPS2(people[k],g,size,myApointers,the_days,k);  
	//REPAIR2(people[k],g,size,myApointers,the_days,k);
}



// for (int k=0;k<size;k++){
	// people[k].length();
	
// }	

         //people[0].display2(myApointers[0 * the_days + 1]);
         //cout<<"day: "<<g<<" person 0 "<<POSSIBLE_COVID_19_INFECTION(people[0],g,infected,people,size,1,2,10,myApointers,the_days,0)<<endl;
    //     cout<<"day: "<<g<<" person 4 "<<POSSIBLE_COVID_19_INFECTION(people[4],g,infected,people,size,1,2,10,myApointers,the_days,4)<<endl;
	
	
	
	 // for (int k=0;k<size-infected;k++){
	
		 // cout<<"day: "<<g<<" person "<<k<<" "<<POSSIBLE_COVID_19_INFECTION(people[k],g,infected,people,size,1,2,10,myApointers,the_days,k)<<endl;
	 // }
	
       //  FIND_CROWDED_PLACES(size,the_days,myApointers,g,20,20,500,500,5,people);


    //     people[1].display();
        // CREATE_GAPS(g,people[1],myApointers,1,size);
    //    // people[1].display();
        // REPAIR(g,people[1],myApointers,1,size);
    //     //people[1].display();

    //     SUMMARIZE_TRAJECTORY(g,43, people[1],344,myApointers,1, the_days);
    //     people[1].display();

    }

    //people[0].display();

for (int k=0;k<size;k++){
        people[k].display();
    }


for (int k=0;k<size;k++){
	people[k].length();
	
}	
 



    return 0;
}