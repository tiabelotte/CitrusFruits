#include <kipr/botball.h>
#define blackThresh 3800
//Black usually has around 4000
//White usually has around 3300
#define claw 1
#define arm 0

void line_follow(int threshold, int distance);
void turn_left(int time);
void turn_right(int time);
void forward_for(int distance, int speed);
void turn_for(int angle, int speed);
/*Line follow: args are threshold and distance*/
void line_follow(int threshold, int distance) {
  while(get_create_distance() < distance) {
    printf("Value: %d \n" , get_create_distance());
    msleep(100);
    if(analog(0)>=threshold) {
      turn_right(3);
    }
    if(analog(0)<=threshold) {
      turn_left(3);
    }
  }
}

/*Turning to the left*/
void turn_left(int time) {
  int i = 0;
  while(i++<=time) {
    create_drive_direct(-80,-100);
  }
}

/*Turning to the right*/
void turn_right(int time) {
  int i = 0;
  while(i++<=time) {
    create_drive_direct(-100, -80);
  }
}

/*goes forward for distance*/
void forward_for(int distance, int speed) {
  set_create_distance(0);

  while (get_create_distance() < distance ) {
    create_drive_direct(speed,speed);
    printf("value is %d", get_create_distance());
    msleep(100);
  }

  create_drive_direct(0,0);
}



/*turns for a specified angle*/

void turn_for(int angle, int speed) {

  set_create_total_angle(0);

  if (speed > 0) {
    while (get_create_total_angle() >-angle) {
      create_spin_CW(speed);
    }
    create_spin_CW(0);
  }

  else if (speed < 0) {

    while (get_create_total_angle() < angle) {
      create_spin_CW(speed);
    }

    create_spin_CW(0);
  } 

}





//main stuff haha
int main()
{
  create_connect();  
  printf("create connected"); 
  set_create_total_angle(0);
  //create setup

  turn_for(10, -200); //Turns the create around
  
  //does some important stuff
  create_drive_direct(-100, -100);
  set_servo_position(claw, 1561);
  enable_servos();
  msleep(300);

  set_servo_position(arm, 1850); //arm down
  msleep(500);
  set_servo_position(claw, 1000);
  msleep(500);
  set_servo_position(arm, 1643); //grabs ball
  msleep(500);

  turn_for(36, 200); //spins onto first black path to line follow later
  msleep(500);

  forward_for(50, -100); //moves forward onto the black line

  line_follow(blackThresh , 212); //starts following the black line
  set_servo_position(claw, 1561); //drops ball
  //dropped ball already
  msleep(400);

  forward_for(500, 100); //back it up back it up

  set_servo_position(arm, 245); //holds the arm up
  msleep(100);
  set_create_distance(0);
  turn_for(10, 200);    //turn a little
  msleep(500);

  create_drive_direct(-200, -200); //goes onto the black line to line follow later
  msleep(500);

  create_drive_direct(0,0); //stops itself
  msleep(500);

  turn_for(3, 200); //turn again for a little bit
  msleep(400);

  create_drive_direct(-200, -200); //Drives forward a little bit to the next black line
  msleep(1500);
  create_drive_direct(0,0);

 turn_for(7, 200);    //turn for a little bit more

  create_drive_direct(-230,-230); //Drives itself into the middle lane
  msleep(4000);

  create_drive_direct(0,0); //Reset stuff
  set_create_total_angle(0);

  while(analog(0) < blackThresh) { //Align itself using line following in the middle lane
     create_spin_CW(50);
     printf("Value is %d \n", analog(0));

     if(digital(0) >= blackThresh) {
      printf("I have found the middle black line!");
      create_spin_CW(1); //Angle itself so it is exactly on the black line
     }
  }

  create_spin_CW(0); //resets something for some reason why is this here?


  set_servo_position(claw, 1561); //grabs the red cube
  msleep(200);
  set_servo_position(arm, 1984);
  msleep(500);
  set_servo_position(claw, 1144);
  msleep(500);

  return 0;
}
