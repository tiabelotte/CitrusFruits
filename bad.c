/**



**/



#include <stdio.h>
#include <unistd.h>


#define IFS = 0;

//Variable declerations 
const int leftStart = 0;
const int leftEnd = 0;

const int rightStart = 0;
const int rightEnd = 0;
const int middle = 0;

const int correctTime = 100;
const int multMult = 0.01;
int currentTime = 0;

int  failureCount = 0;
bool running = true;
bool movingState = 0;

int speedMult = 1;
int steerMult = 1;

while (running) {
	currentTime++;

	bool leftDetect = 	(sensorInput >= leftStart ) && (sensorInput <= leftEnd );
	bool rightDetect = 	(sensorInput >= rightStart) && (sensorInput <= rightEnd);
	bool messUp = false;

	if (startDetect) {
		//0 = hasn't reached start yet; 1 = has hit starting line; 2 = passed starting line
		//although we could have just placed the robot on the starting line 
		if (movingState = 0) movingState = 1;
		//End and set
		else if (movingState = 2) {
			running = false;
			speedMult = correctTime/currentTime;
		}
	else if(movingState = 1) movingState = 2;

	} else {
		//Detect and correct if move to side
		if (leftDetect)  {
			messUp = true;
			print("Error: Veered Left" ); 
			steerMult = currentTime * multMult;
		}
		if (rightDetect) {
			messUp = true;
			print("Error: Veered Right");
			steerMult = currentTime * multMult *-1;
		}
	}

	if(isMoving && !messUp) {
		moving2 = true;
	}

	if (messUp) failureCount++;
	if (failureCount > 20) running=0;

}