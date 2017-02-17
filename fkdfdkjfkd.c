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
