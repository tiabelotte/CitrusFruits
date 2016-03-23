#include <stdio.h>
#include <unistd.h>

#define IFS = 0;

//Variable declerations 
const int leftStart = 0;
const int leftEnd = 0;

const int rightStart = 0;
const int rightEnd = 0;
const int middle = 0;

int  failureCount = 0;
bool running = true;
bool movingState = 0;

while (running) {
	bool leftDetect = false;
	bool rightDetect = false;
	bool messUp = false;

	if (startDetect) {
		if (movingState = 0) movingState = 1;
		else [dsfsdfsd];

	} else {
		if (leftDetect)  { messUp = true; print("Error: Veered Left" ); }
		if (rightDetect) { messUp = true; print("Error: Veered Right"); }
	}

	if(isMoving && !messUp) {
		moving2 = true;
	}

	if (messUp) failureCount++;
	if (failureCount > 20) running=0;

}