/** 
 *@file        IFX007T-Motor-Control.h
 *@brief       IFX007T-Motor-Control Arduino Class
 *@date        January 2020
 *@copyright   Copyright (c) 2020 Infineon Technologies AG
 */

#ifndef IFX007T_MOTOR_CONTROL_H
#define IFX007T_MOTOR_CONTROL_H
/*! @def First Hall Switch */
#define HALL_A A1
/*! @def Second Hall Switch */
#define HALL_B A2
/*! @def Third Hall Switch */
#define HALL_C A3
/*! @def according the different motor it will be changed  */
#define MotorPoles 8
/*! @def  PID Controller params */
#define PI_REG_K 0.01
#define PI_REG_I 0.001
/*! @def  the reference round per min which can set by the users */
#define ReferenceRPM 6500.0
#include <stdio.h>

/**
 *@class IFX007TMotorControl
 */

class IFX007TMotorControl
{
	public:

	void begin();
	void end();
	void setMode(int mode, char pwm_p, int frequencyDivisor, int dutyCycle);
	void setMode(int mode, char pwm_p1, char pwm_p2, int frequencyDivisor, int dutyCycle);
	void setMode(int mode, char pwm_p1, int frequencyDivisor_p1, int dutyCycle_p1, char pwm_p2, int frequencyDivisor_p2, int dutyCycle_p2);
	void setMode(int mode, char pwm_p1, int frequencyDivisor_p1, int dutyCycle_p1, char pwm_p2, int frequencyDivisor_p2, int dutyCycle_p2,
		           char pwm_p3, int frequencyDivisor_p3, int dutyCycle_p3);
	void start(char pwm_p);
	void stop(char pwm_p);
	void setBLDCMode(uint8_t mode, int frequencyDivisor, int DutyCycle);

	private:

	void setPwmFrequency(int pin, int divisor);
	void setAwake_Config(char pin, int frequencyDivisor, int dutyCycle);
	void pI_Regulator_DoWork();
	void commutate();
	uint8_t updateHall();
	void updateHardware(uint8_t CommutationStep);
	/**
	 *variables for Pin Configuration
	 */
	int _INHU = 6;
	int _INHV = 5;
	int _INHW = 3;
	int _INU = 11;
	int _INV = 10;
	int _INW = 9;
	bool _isMotorReady = false;
	bool _ispwmactive_U = false;;
	bool _ispwmactive_V = false;
	bool _ispwmactive_W = false;
	bool _isBLDCactive = false;
	typedef struct
	{
		char pwm_pin;
		int frequencyDivisor;
		int dutyCycle;

	}

	hBridgeParams;

	hBridgeParams pinParams_p1, pinParams_p2, pinParams_p3;
	/*for BLDC motor application*/
	uint8_t CommutationState = 1;
	uint8_t ClosedLoop = 0;
	uint8_t OpenLoopSteps = 100;
	uint16_t OpenLoopDelay = 3000;
	uint8_t bldcDutyCycle;
	uint8_t oldHall, latestHall = 0;
	uint16_t HallCounts = 0;
	unsigned long PI_Update_Timeout = 999999999;
	uint16_t LastRPM = 0;	//the current rotate speed 
	float RefRPM = ReferenceRPM;
	float PI_K = PI_REG_K;
	float PI_I = PI_REG_I;
	float PI_Integral = 0.0;
};

#
endif /**< IFX007_*/