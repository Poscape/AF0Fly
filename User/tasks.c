#include "tasks.h"

int16_t accx_read = 0, accy_read = 0, accz_read = 0;
int16_t gyrox_read = 0, gyroy_read = 0, gyroz_read = 0;
int16_t magx_read = 0, magy_read = 0, magz_read = 0;
int16_t tmp = 0;

// int8_t data[18] = {0};
int8_t data[20] = {0};

extern int dutyCycleArray[6];

/* Delay */
INT16U Task1000HZDelay = 2;
INT16U Task500HZDelay = 2;
INT16U Task250HZDelay = 4;

// INT16U gy86_delay = 150;
// INT16U kalman_delay = 145;
// INT16U send_delay = 80;
// INT16U oled_delay = 15;

// INT16U inner_loop_delay = 10;
// INT16U motor_delay = 5;

// INT16U outer_loop_delay = 3;
// INT16U blink_delay = 1;
/* Delay End */

/* Time */
INT32U gy86_time = 0;
INT32U kalman_time = 0;
INT32U send_time = 0;
INT32U oled_time = 0;

INT32U inner_loop_time = 0;
INT32U motor_time = 0;

INT32U outer_loop_time = 0;
INT32U blink_time = 0;
/* Time End */

/* Task Stacks */
OS_STK Task1000HZStk[600];
// OS_STK GY86TaskStk[100];
// OS_STK KalmanTaskStk[300];
// OS_STK SendTaskStk[100];
// OS_STK OLEDTaskStk[100];

OS_STK Task500HZStk[200];
// OS_STK InnerLoopTaskStk[100];
// OS_STK MotorTaskStk[100];

OS_STK Task250HZStk[200];
// OS_STK OuterLoopTaskStk[100];
// OS_STK BlinkTaskStk[100];
/* Task Stacks End */

/*
*********************************************************************************************************
*                                             1000Hz TASKS
*
* Includes:
* 0. Task1000HZ
* 1. GY86Task
* 2. KalmanTask
* 3. SendTask
* 4. OLEDTask
*********************************************************************************************************
*/

void Task1000HZ(void *p_arg)
{
	while (1)
	{
		GY86Task();
		KalmanTask();
		SendTask();
		OLEDTask();
		OSTimeDlyHMSM(0, 0, 0, Task1000HZDelay);
	}
}

void GY86Task()
{
	// Gy86: MPU6050(Accelerometer, Gyroscope), HMC5883(Magnetometer)
	INT32U tick1 = OSTimeGet();

	I2C1_GetAll(data);
	accx_read = (int16_t)((data[0] << 8) + data[1]);
	accy_read = (int16_t)((data[2] << 8) + data[3]);
	accz_read = (int16_t)((data[4] << 8) + data[5]);
	tmp = (int16_t)((data[6] << 8) + data[7]) * 10;
	gyrox_read = (int16_t)((data[8] << 8) + data[9]);
	gyroy_read = (int16_t)((data[10] << 8) + data[11]);
	// gyroz_read = (int16_t)((data[12] << 8) + data[13]);
	gyroz_read = (int16_t) I2C1_GetGyroZ();
	
	magx_read = (int16_t)((data[14] << 8) + data[15]);
	magy_read = (int16_t)((data[16] << 8) + data[17]);
	magz_read = (int16_t)((data[18] << 8) + data[19]);

	INT32U tick2 = OSTimeGet();
	gy86_time = tick2 - tick1;
}

void KalmanTask()
{
	INT32U tick1 = OSTimeGet();

	ekf_calculate();

	INT32U tick2 = OSTimeGet();
	kalman_time = tick2 - tick1;
}

void SendTask()
{
	INT32U tick1 = OSTimeGet();

	FANO_Send_Data(0x01, (uint8_t *)ano_mpu_data);
	// FANO_Send_MAG(data);
	FANO_Send_Data(Frame_Quaternion, (uint8_t *)ano_data);
	// FANO_Send_Data(Frame_EulerAngle, (uint8_t *)ano_data_euler);


	INT32U tick2 = OSTimeGet();
	send_time = tick2 - tick1;
}

void OLEDTask()
{
	int mode = 2;

	INT32U tick1 = OSTimeGet();

	if (mode == 0) // GY86 Mode
	{
		OLED_ShowString(1, 1, "T:");
		OLED_ShowNum(1, 3, OSTime, 5);

		OLED_ShowString(2, 1, "X");
		OLED_ShowSignedNum(2, 2, accx_read, 4);
		OLED_ShowSignedNum(2, 7, gyrox_read, 4);
		OLED_ShowSignedNum(2, 12, magx_read, 4);

		OLED_ShowString(3, 1, "Y");
		OLED_ShowSignedNum(3, 2, accy_read, 4);
		OLED_ShowSignedNum(3, 7, gyroy_read, 4);
		OLED_ShowSignedNum(3, 12, magy_read, 4);

		OLED_ShowString(4, 1, "Z");
		OLED_ShowSignedNum(4, 2, accz_read, 4);
		OLED_ShowSignedNum(4, 7, gyroz_read, 4);
		OLED_ShowSignedNum(4, 12, magz_read, 4);
	}
	else if (mode == 1) // Motor Mode
	{
		OLED_ShowString(1, 1, "T:");
		OLED_ShowNum(1, 3, OSTime, 5);

		OLED_ShowNum(2, 1, dutyCycleArray[0], 3);
		OLED_ShowNum(2, 5, dutyCycleArray[1], 3);
		OLED_ShowNum(3, 1, dutyCycleArray[2], 3);
		OLED_ShowNum(3, 5, dutyCycleArray[3], 3);
		OLED_ShowNum(4, 1, dutyCycleArray[4], 3);
		OLED_ShowNum(4, 5, dutyCycleArray[5], 3);
	}
	else if (mode == 2) // Time Mode
	{
		OLED_ShowString(1, 1, "G:");
		OLED_ShowNum(1, 3, gy86_time, 4);
		OLED_ShowString(1, 9, "K:");
		OLED_ShowNum(1, 11, kalman_time, 4);
		OLED_ShowString(2, 1, "S:");
		OLED_ShowNum(2, 3, send_time, 4);
		OLED_ShowString(2, 9, "O:");
		OLED_ShowNum(2, 11, oled_time, 4);

		OLED_ShowString(3, 1, "I:");
		OLED_ShowNum(3, 3, inner_loop_time, 4);
		OLED_ShowString(3, 9, "M:");
		OLED_ShowNum(3, 11, motor_time, 4);

		OLED_ShowString(4, 1, "O:");
		OLED_ShowNum(4, 3, outer_loop_time, 4);
		OLED_ShowString(4, 9, "B:");
		OLED_ShowNum(4, 11, blink_time, 4);
	}

	INT32U tick2 = OSTimeGet();
	oled_time = tick2 - tick1;
}

/*
*********************************************************************************************************
*                                             500Hz TASKS
*
* Includes:
* 0. Task500HZ
* 1.InnerLoopTask
* 2.MotorTask
*********************************************************************************************************
*/
void Task500HZ(void *p_arg)
{
	while (1)
	{
		InnerLoopTask();
		MotorTask();
		OSTimeDlyHMSM(0, 0, 0, Task500HZDelay);
	}
}
void InnerLoopTask()
{
	INT32U tick1 = OSTimeGet();

	// TODO: Inner Loop

	INT32U tick2 = OSTimeGet();
	inner_loop_time = tick2 - tick1;
}

void MotorTask()
{
	INT32U tick1 = OSTimeGet();

	PWM_output();

	INT32U tick2 = OSTimeGet();
	motor_time = tick2 - tick1;
}

/*
*********************************************************************************************************
*                                             250Hz TASKS
*
* Includes:
* 0. Task250HZ
* 1. OuterLoopTask
* 2. BlinkTask
*********************************************************************************************************
*/
void Task250HZ(void *p_arg)
{
	while (1)
	{
		OuterLoopTask();
		BlinkTask();
		OSTimeDlyHMSM(0, 0, 0, Task250HZDelay);
	}
}

void OuterLoopTask()
{
	INT32U tick1 = OSTimeGet();

	// TODO: Outer Loop

	INT32U tick2 = OSTimeGet();
	outer_loop_time = tick2 - tick1;
}

void BlinkTask()
{
	BOOLEAN flag = 0;

	INT32U tick1 = OSTimeGet();

	if (flag == 0)
		LED_On();
	else
		LED_Off();

	flag = !flag;

	INT32U tick2 = OSTimeGet();
	blink_time = tick2 - tick1;
}