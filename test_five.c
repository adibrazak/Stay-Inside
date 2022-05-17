#include <ev3.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#define EV3SENSOR_H
#define THRESHOLD 15

//rotate factor variable
float rf = 2.75;

//declare counter
int i=1;

//declare motor rotation angle
int r;
char str[20];

//declare random number variable
int a, b;

//declare range of random number
int minRotate = -500;
int maxRotate = 500;
int minRotateLeft = -270;
int maxRotateLeft = -90;
int minRotateRight = 90;
int maxRotateRight = 270;

//function to randomly rotate robot in place
void randomRotateInPlace()
{
	a = rand()%(maxRotate-minRotate + 1) + minRotate;

	if (a<0)
	{
		b = rand()%(maxRotateLeft-minRotateLeft + 1) + minRotateLeft;
		r = b*rf; //multiply rotation factor
		RotateMotorEx(OUT_BC, 50, r, 200 , true, true);
		Wait(300);
	}
	else
	{
		b = rand()%(maxRotateRight-minRotateRight + 1) + minRotateRight;
		r = b*rf; //multiply rotation factor
		RotateMotorEx(OUT_BC, -50, r, 200 , true, true);
		Wait(300);
	}
}

//function to randomly move robot
void randomMove()
{
	while(1)
	{
		if (ReadSensor(IN_1) < THRESHOLD)
		{
			Off(OUT_BC);
			break;
		}

		else
		{
			OnFwdEx(OUT_BC, 90,	true);
		}
	}
}

int main()
{
	InitEV3();
	setAllSensorMode(COL_REFLECT, NO_SEN, NO_SEN, NO_SEN);

	while(1)
	{
		if (ButtonIsDown(BTNCENTER) == 1)
		{
			return;
			Off(OUT_BC);
			break;
		}

		else
		{
			//robot action
			randomMove();
			Wait(1000);
			RotateMotorEx(OUT_BC, -70, 120, 0 , true, true);
			randomRotateInPlace();
			Wait(1000);

			}
	}

FreeEV3();
return 0;
}
