/*Including header files*/
#include <kipr/botball.h>
#include <stdio.h>
/*Defining motor and servo ports*/
#define LM 0
#define RM 1
#define SVO 0
#define RSVO 1
#define LSVO 2
#define MSVO 3
#define HS 100
#define NS 80
#define TS -10
#define PS -100
#define right_angle 190
/*Function prototypes*/
void drive_forwards_fast(int time);
void drive_forwards_slow(int time);
void drive_backwards_fast(int time);
void drive_backwards_slow(int time);
void turn_left(int time);
void turn_right(int time);
void pivot_left(int time);
void pivot_right(int time);
void line_followL(int threshold, int time);
void line_followR(int threshold, int time);
void line_follow_backwardsL(int threshold, int time);
void line_follow_backwardsR(int threshold, int time);
void aosleep(int ms);


/*Main Function*/

int main() {
  //Setup
  //Line following threshold
  int current_threshold = 2500;
  enable_servos();
  
  //Grab with arm//
  set_servo_position(SVO,310);
  set_servo_position(LSVO,931);
  set_servo_position(RSVO,968);
  set_servo_position(MSVO,1015);
  aosleep(1000);
  
  //Move out of box//
  drive_forwards_slow(150); //Driving out of the starter box
  set_servo_position(SVO,50);
  set_servo_position(LSVO,1604);
  set_servo_position(RSVO,312);
  aosleep(200);
  set_servo_position(SVO,350);
  aosleep(150);
  set_servo_position(SVO,750);
  aosleep(300);
  drive_forwards_slow(200); //Driving w/arm up
  
  //Turn and drive to wall//
  pivot_right(right_angle); //Turn towards center of the board
  aosleep(100);
  while (digital(0)!=1) {
    drive_forwards_fast(1); //drive towards pvc
  }
  aosleep(250);
  
  //Reorient to ramp//
  drive_backwards_fast(100);
  pivot_left(right_angle-20); //Turn vaguely towards the ramp
  aosleep(70);
  //drive_backwards_fast(25);
  //aosleep(500);
  
  //Drive up ramp//
  drive_forwards_fast(250); //Drive towards the ramp
  
  while(digital(0)!=1) {
    line_followR(current_threshold,5); //Line follows until it hits the PVC on top of the ramp
  }
  
  //Reverse and turn towards boxes//
  drive_backwards_fast(75); //reverse
  aosleep(250);
  
  pivot_right(190); //turn towards opposite side of board
  aosleep(50);
  pivot_right(35);
  aosleep(50);
  
  while (digital(0)!=1) {
    drive_forwards_fast(1);
  }
  aosleep(50);
  set_servo_position(MSVO,1401);
  
  //Drive back, then line follow//
  drive_backwards_fast(25);
  set_servo_position(SVO,1475);
  line_follow_backwardsL(current_threshold,150);
  set_servo_position(MSVO,277);
  msleep(1000);
  
  
  
  
  /*
  
  set_servo_position(SVO,390);
  aosleep(1000);
  set_servo_position(LSVO,861);
  set_servo_position(RSVO,1221);
*/
  return 0;



}


/*Function declarations*/
void drive_forwards_fast(int time) {
  int i = 0;
  while(i++<=time) {
    motor(LM,HS);
    motor(RM,HS);
  }
}
void drive_forwards_slow(int time) {
  int i = 0;
  while(i++<=time) {
    motor(LM,NS);
    motor(RM,NS);
  }
}
void drive_backwards_fast(int time) {
  int i = 0;
  while(i++<=time) {
    motor(LM,-HS);
    motor(RM,-HS);
  }
}
void drive_backwards_slow(int time) {
  int i = 0;
  while(i++<=time) {
    motor(LM,-NS);
    motor(RM,-NS);
  }
}
void turn_left(int time) {
  int i = 0;
  while(i++<=time) {
    motor(RM,HS);
    motor(LM,TS);
  }
}
void turn_right(int time) {
  int i = 0;
  while(i++<=time) {
    motor(RM,TS);
    motor(LM,HS);
  }
}
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
void line_followL(int threshold, int time) {
  int i = 0;
  while(i++<time) {
    if(analog(0)<=threshold) {
      for(i=0; i<5; i++) {
        motor(LM,100);
        motor(RM,65);
      } 
    }
    if(analog(0)>=threshold) {
      int i=0;
      for(i=0; i<5; i++) {
        motor(RM,100);
        motor(LM,65);
      }   
    }
  }
}
void line_followR(int threshold, int time) {
  int i = 0;
  while(i++<time) {
    if(analog(0)<=threshold) {
      for(i=0; i<5; i++) {
        motor(RM,100);
        motor(LM,65);
      } 
    }
    if(analog(0)>=threshold) {
      int i=0;
      for(i=0; i<5; i++) {
        motor(LM,100);
        motor(RM,65);
      }   
    }
  }
}
void line_follow_backwardsL(int threshold, int time) {
  int i = 0;
  while(i++<time) {
    if(analog(0)<=threshold) {
      for(i=0; i<5; i++) {
        motor(LM,-100);
        motor(RM,-65);
      } 
    }
    if(analog(0)>=threshold) {
      int i=0;
      for(i=0; i<5; i++) {
        motor(RM,-100);
        motor(LM,-65);
      }   
    }
  }
}
void line_follow_backwardsR(int threshold, int time) {
  int i = 0;
  while(i++<time) {
    if(analog(0)<=threshold) {
      for(i=0; i<5; i++) {
        motor(RM,-100);
        motor(LM,-65);
      } 
    }
    if(analog(0)>=threshold) {
      int i=0;
      for(i=0; i<5; i++) {
        motor(LM,-100);
        motor(RM,-65);
      }   
    }
  }
}

//Stop & sleep
void aosleep(int ms) {
  ao();
  msleep(ms);
}








