#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;


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

int theTime;

int started_moving;

float ultimate_x;
float ultimate_y;


struct coordinates{
    float xi;
    float yi;
};
void choose_rad_possition(float &a,float &b){
    a = (rand() % 10) + 1;
    b = (rand() % 10) + 1;
}
void choose_rad_speed(int &speed){
  int i = (rand() % 2) + 1;
  if (i==1)speed=10;
  else speed=20;
}
void choose_rad_timelapse(int &timelapse){
    timelapse = (rand() % 20) + 1;
    timelapse +=2;
    timelapse += theTime;
}
float move(float xt,float yt,float xa,float ya,float velocity){
    
    float divVelocity = (float)velocity;
    int temp1 = (xt - xa)*(xt - xa) + (yt - ya)*(yt - ya) ; //Dt = apostasi shmeiwn/metro taxititas
    float temp2 = (float)temp1;
    temp2 = sqrt (temp2);

    return temp2 / divVelocity ;

}

//find Vx and Vy
void caLculate_speeds(float &v1,float &v2,int xt,int yt,int xa,int ya,int ta,float tt){
    v1 = (xt - xa)/(tt - ta);
    v2 = (yt - ya)/(tt - ta);
}
//calculate every sec
coordinates find_possition(float xa,float ya,float v1,float v2,int t,int ta){

    float xix = xa + v1*(t-ta);
    float yiy = ya + v2*(t-ta);

   // cout << xa << " " << v1 << " " << t-ta << " " << v1*(t-ta) << " " << xa + v1*(t-ta)<< endl;
    coordinates xy={xix,yiy};
    return xy;
}
void choose_rad_speed(float &myvelocity){

    int i = (rand() % 9) + 1;
    i+=7;
    //cout<<i<<endl;
    float div = (float)i;
    myvelocity = div/10;
}



int main(){
    srand((int)time(0));
    //cout<<move(1,1,0,0,0,1)<<endl;
    //caLculate_speeds(Vx,Vy,10,10,5,5,0,1);
    //cout<<Vx<<" "<<Vy<<endl;
    //coordinates xy = find_possition(5,5,4,4,1,0);
    //cout<<xy.xi<<" "<<xy.yi<<endl;
    //choose_rad_speed(v);
    //cout<<v<<endl;

    
    theTime=0;
    choose_rad_possition(xs,ys);    // choose a random possition xs,ys to start
    choose_rad_timelapse(delay);    //choose time to wait
    cout << xs << " " << ys << " " << delay << endl;

    ultimate_x=xs;
    ultimate_y=ys;

    
    while(theTime<30){
        theTime+=1;
        
        cout<<"clock:"<<theTime<<endl;
        if (theTime<delay)cout<<"i am waiting"<<endl;
        
        else if(theTime<sec){
            cout << "i am moving now" << endl;
            coordinates xy = find_possition(xs,ys,Vx,Vy,theTime,started_moving);
            //cout << xs << " " << ys << " " << Vx << " " << Vy << " " << theTime<< " " << sec << endl;
            cout<<xy.xi<<" "<<xy.yi<<endl;
            ultimate_x=xy.xi;
            ultimate_y=xy.yi;

        }
        
        else if(theTime==sec){
            //reached the possition / start waiting //
            cout<<"i reached the possition"<<endl;
            choose_rad_timelapse(delay);
            xs=x;
            ys=y;
            cout << xs << " " << ys << " " << delay << endl;

            
            ultimate_x=xs;
            ultimate_y=ys;


        }

        else {

            
            cout << "i will start moving now" << endl;
            choose_rad_possition(x,y);// choose a random possition x,y to go
            cout << x << " " << y << " "  << endl;
            choose_rad_speed(v);//choose a random speed
            cout << v << endl;
            sec=move(x,y,xs,ys,v);//find dt
            cout << sec << endl;
            sec+=theTime;
            started_moving = theTime; //save the time you start moving
            caLculate_speeds(Vx,Vy,x,y,xs,ys,theTime,sec); //find Vx, Vy
            cout << Vx << " " << Vy << " "  << endl;
        }

        cout << "My possition is : " << ultimate_x << " " << ultimate_y <<  endl;
    }


    //choose_rad_speed(v);

    //cout << x0 << " " << y0 << " " << v << endl;

    return 0;
}
