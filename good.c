/*Code written by Joseph Farah (sometime in March)
/*Including header files*/
/*Code for Matt Damon*/
#include <kipr/botball.h>
#include <stdio.h>
/*Defining motor and servo ports*/
/*Motor ports*/
#define LM 0
#define RM 1
/*Servo ports*/
#define SVO 0
#define RSVO 1
#define LSVO 2
/*Speeds*/
#define HS 100
#define NS 80
#define TS -10
#define PS -100
/*How many iterations to turn in a perfect right angle*/
#define right_angle 170
/*Function prototypes*/
/*See function definitions for descriptions*/
void drive_forwards_fast(int time);
void drive_forwards_slow(int time);
void drive_backwards_fast(int time);
void turn_left(int time);
void turn_right(int time);
void pivot_left(int time);
void pivot_right(int time);
void line_follow(int threshold, int time);

/*Main Function*/
int main() {
  /*Initializing the threshold of white-black; 
  number subject to change*/
  int current_threshold = 2500;
  enable_servos();
  /*Raise the arm just above the solar arrays 
  and prepare to grasp them*/
  set_servo_position(SVO,310);
  set_servo_position(LSVO,931);
  set_servo_position(RSVO,968);
  msleep(1000);
  /*Drive onto the solar arrays*/
  drive_forwards_fast(8);
  /*Grasp the arrays*/
  set_servo_position(SVO,50);
  set_servo_position(LSVO,1604);
  set_servo_position(RSVO,312);
  msleep(1000);
  /*Lift them in "balanced position"*/
  set_servo_position(SVO,750);
  /*Drive up to the slope*/
  pivot_right(right_angle);
  drive_forwards_fast(330);
  pivot_left(right_angle);
  drive_forwards_fast(700);
  /*Line follow to secure position*/
  line_follow(current_threshold,280);
  drive_forwards_fast(300);
  return 0;
  
  
  
  
}


/*Function declarations*/
/*Driving forwards fast*/
void drive_forwards_fast(int time) {
  int i = 0;
  while(i++<=time) {
    motor(LM,HS);
    motor(RM,HS);
  }
}
/*Driving forwards at about two thirds of "fast"*/
void drive_forwards_slow(int time) {
  int i = 0;
  while(i++<=time) {
    motor(LM,NS);
    motor(RM,NS);
  }
}
/*Driving backwards fast*/
void drive_backwards_fast(int time) {
  int i = 0;
  while(i++<=time) {
    motor(LM,PS);
    motor(RM,PS);
  }
}
/*Turning to the left*/
void turn_left(int time) {
  int i = 0;
  while(i++<=time) {
    motor(RM,HS);
    motor(LM,TS);
  }
}
/*Turning to the right*/
void turn_right(int time) {
  int i = 0;
  while(i++<=time) {
    motor(RM,TS);
    motor(LM,HS);
  }
}
/*Pivot on point--NOT turning*/
void pivot_left(int time) {
  int i = 0;
  while(i++<=time) {
    motor(LM,PS);
    motor(RM,HS);
  }
}
void pivot_right(int time) {
  int i = 0;
  while(i++<=time) {
    motor(LM,HS);
    motor(RM,PS);
  }
}
/*Line follow: arguments are whatever threshold we are using, 
plus however many iterations we want the function to perform*/
void line_follow(int threshold, int time) {
  int i = 0;
  while(i++<time) {
    if(analog(0)>=threshold) {
      turn_right(3);
    }
    if(analog(0)<=threshold) {
      turn_left(3);
    }
  }
}










