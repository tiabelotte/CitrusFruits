#include <stdio.h>
#include <unistd.h>

#define LM 0
#define RM 1

void drive_forwards(int time);
void turn_left(int time);
void turn_right(int time);
void drive_backwards(int time);

int main() {
	//Put your FUCKING code here, dipshits

}

void drive_forwards(int time) {
	//motor(LM,100);
	//motor(RM,100);
	// printf("This code drives forwards for %d seconds.\n", i);
	int i = 0;
	printf("This code drives forwards for %d seconds.\n", i);
	while(i<time) {
		printf("Driving forwards... %d\n", i);
		sleep(1);
		i++;
	}
}
void turn_left(int time) {
	//motor(LM,10);
	//motor(RM,100);
	// printf("This code turns left for %d seconds.\n", i);
	int i = 0;
	printf("This code turns left for %d seconds.\n", i);
	while(i<time) {
		printf("Turning left... %d\n", i);
		sleep(1);
		i++;
	}
}
void turn_right(int time) {
	//motor(LM,100);
	//motor(RM,10);
	// printf("This code turns right for %d seconds.\n", i);
	int i = 0;
	printf("This code turns right for %d seconds.\n", i);
	while(i<time) {
		printf("Turning right... %d\n", i);
		sleep(1);
		i++;
	}
}
void drive_backwards(int time) {
	//motor(0,-100);
	//motor(1,-100);
	int i = 0;
	printf("This code drives backwards for %d seconds.\n", i);
	while(i<time) {
		printf("Driving backwards... %d\n", i);
		sleep(1);
		i++;
	}
}