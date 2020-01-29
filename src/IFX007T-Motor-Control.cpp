/**
 *@file        IFX007T-Motor-Control.cpp
 *@brief       IFX007T-Motor-Control Arduino Class
 *                  
 *        Arduino wrapper for IFX007T-Motor-Control Sheild
 *        - Hardware Allocation using direct arduino pins
 *        - Predefined Arduino based hardware platforms: IFX007T-Motor-Control Sheild + (XMC Arduino / Arduino UNO)
 *
 *@date        January 2020
 *@copyright   Copyright (c) 2019 Infineon Technologies AG
 */
#include "Arduino.h"
#include "IFX007T-Motor-Control.h"

/**
 *@brief     Begin will perform Motor Shield pin initilalization
 *@return    Void
 */

void IFX007TMotorControl::begin()
{
	_isMotorReady = true;
	pinMode(_INHU, OUTPUT);
	pinMode(_INHV, OUTPUT);
	pinMode(_INHW, OUTPUT);
	pinMode(_INU, OUTPUT);
	pinMode(_INV, OUTPUT);
	pinMode(_INW, OUTPUT);
	digitalWrite(_INHU, LOW);
	digitalWrite(_INHV, LOW);
	digitalWrite(_INHW, LOW);
	digitalWrite(_INU, LOW);
	digitalWrite(_INV, LOW);
	digitalWrite(_INW, LOW);
	pinMode(HALL_A, INPUT_PULLUP);
	pinMode(HALL_B, INPUT_PULLUP);
	pinMode(HALL_C, INPUT_PULLUP);
	pinMode(13, OUTPUT);
	pinParams_p1.dutyCycle = 0;
	pinParams_p1.frequencyDivisor = 1;
	pinParams_p1.pwm_pin = NULL;
	pinParams_p2.dutyCycle = 0;
	pinParams_p2.frequencyDivisor = 1;
	pinParams_p2.pwm_pin = NULL;
	pinParams_p3.dutyCycle = 0;
	pinParams_p3.frequencyDivisor = 1;
	pinParams_p3.pwm_pin = NULL;
	bldcDutyCycle = 0;

}

/**
 *@brief For mode 1, IFX007TMotorControl can generate PWM

 *@param mode For Uni Directional motor control, mode is set to 1
 *@param pwm_pin Select any one pin (U, V or W)
 *@param frequencyDivisor To select Frequency at pin
 *@param dutyCycle Duty Cycle for PWM at Selected pin

 *@return void
 */
void IFX007TMotorControl::setMode(int mode, char pwm_pin, int frequencyDivisor, int dutyCycle)
{
	if (_isMotorReady)
	{
		if (mode == 1)
		{
			setAwake_Config(pwm_pin, frequencyDivisor, dutyCycle);
		}
	}
}

/**
 *@brief For mode 1, IFX007TMotorControl can generate PWM

 *@param mode (Two different pins with same frequency and dutycycle)
 *@param pwm_p1 Select any one pin (U, V or W)
 *@param pwm_p2 Select pin  other than pwm_p1
 *@param frequencyDivisor To select Frequency for both
 *@param dutyCycle Duty Cycle for PWM for both pins

 *@return void
 */

void IFX007TMotorControl::setMode(int mode, char pwm_p1, char pwm_p2, int frequencyDivisor, int dutyCycle)
{
	if (_isMotorReady)
	{
		if (pwm_p1 != pwm_p2)	// no function if both pins are same
		{
			if (mode == 1)
			{
				setAwake_Config(pwm_p1, frequencyDivisor, dutyCycle);
				setAwake_Config(pwm_p2, frequencyDivisor, dutyCycle);

			}
		}
	}
}

/**
 *@brief For mode 1, IFX007TMotorControl can generate PWM

 *@param mode (Two different pins with different frequency and dutycycle)
 *@param pwm_p1 Select any one pin (U, V or W)
 *@param pwm_p2 Select pin  other than pwm_p1
 *@param frequencyDivisor_p1 To select Frequency for p1
 *@param dutyCycle_p1 Duty Cycle for PWM for p1
 *@param frequencyDivisor_p2 To select Frequency for p2
 *@param dutyCycle_p2 Duty Cycle for PWM for p2

 *@return void
 */
void IFX007TMotorControl::setMode(int mode, char pwm_p1, int frequencyDivisor_p1, int dutyCycle_p1, char pwm_p2, int frequencyDivisor_p2, int dutyCycle_p2)
{
	if (_isMotorReady)
	{
		if (pwm_p1 != pwm_p2)	// no function if pins are same
		{
			if (mode == 1)
			{
				setAwake_Config(pwm_p1, frequencyDivisor_p1, dutyCycle_p1);
				setAwake_Config(pwm_p2, frequencyDivisor_p2, dutyCycle_p2);

			}
		}
	}
}

/**
 *@brief For mode 1, IFX007TMotorControl can generate PWM

 *@param mode (Three different pins with different frequency and dutycycle)
 *@param pwm_p1 Select any one pin (U, V or W)
 *@param frequencyDivisor_p1 To select Frequency for p1
 *@param dutyCycle_p1 Duty Cycle for PWM for p1
 *@param pwm_p2 Select pin  other than pwm_p1
 *@param frequencyDivisor_p2 To select Frequency for p2
 *@param dutyCycle_p2 Duty Cycle for PWM for p2
  *@param pwm_p3 Select pin  other than pwm_p1 and pwm_p2
 @param frequencyDivisor_p3 To select Frequency for p2
 *@param dutyCycle_p3 Duty Cycle for PWM for p2

 *@return void
 */

void IFX007TMotorControl::setMode(int mode, char pwm_p1, int frequencyDivisor_p1, int dutyCycle_p1,
	char pwm_p2, int frequencyDivisor_p2, int dutyCycle_p2,
	char pwm_p3, int frequencyDivisor_p3, int dutyCycle_p3)
{
	if (_isMotorReady)
	{
		if (mode == 1)
		{
			setAwake_Config(pwm_p1, frequencyDivisor_p1, dutyCycle_p1);
			setAwake_Config(pwm_p2, frequencyDivisor_p2, dutyCycle_p2);
			setAwake_Config(pwm_p3, frequencyDivisor_p3, dutyCycle_p3);

		}
	}
}

/**
 *@brief For mode 2, IFX007TMotorControl can generate run a BLDC motor with HALL Switches
 *@param mode
 *@param frequencyDivisor To select Frequency for the Three Phase Motor
 *@param dutyCycle Duty Cycle for PWM
 *@return Void
 */
void IFX007TMotorControl::setBLDCMode(uint8_t mode, int frequencyDivisor, int dutyCycle)
{
	if (_isMotorReady)
	{
		if (mode == 2)
		{
			bldcDutyCycle = dutyCycle;
			pinParams_p1.pwm_pin = '#';
			setAwake_Config('#', frequencyDivisor, bldcDutyCycle);

		}
	}
}

/**
 *@brief setAwake_Config will Awake the selected pin by making the inhibitor HIGH, so the Pin comes out of sleep mode
 *@param pwm_pin The corresponding Inhibitor pin is set to awake mode from sleep mode
 *@param frequencyDivisor To setPwmFrequency Function as parameter
 *@param dutyCycle To setPwmFrequency Function as parameter
 *@return Void 
 */

void IFX007TMotorControl::setAwake_Config(char pwm_pin, int frequencyDivisor, int dutyCycle)
{
	// for bldc

	if (pwm_pin == '#')
	{
		setPwmFrequency(_INU, frequencyDivisor);
		setPwmFrequency(_INV, frequencyDivisor);
		setPwmFrequency(_INW, frequencyDivisor);

	}

	if (pwm_pin == 'U')
	{
		pinParams_p1.pwm_pin = 'U';
		pinParams_p1.dutyCycle = dutyCycle;
		digitalWrite(_INHU, HIGH);
		setPwmFrequency(_INU, frequencyDivisor);

	}
	else if (pwm_pin == 'V')
	{
		pinParams_p2.pwm_pin = 'V';
		pinParams_p2.dutyCycle = dutyCycle;
		digitalWrite(_INHV, HIGH);
		setPwmFrequency(_INV, frequencyDivisor);

	}
	else if (pwm_pin == 'W')
	{
		pinParams_p3.pwm_pin = 'W';
		pinParams_p3.dutyCycle = dutyCycle;
		digitalWrite(_INHW, HIGH);
		setPwmFrequency(_INW, frequencyDivisor);

	}
}

/**
 *@brief Divides a given PWM pin frequency by a divisor.
 *
 *-The resulting frequency is equal to the base frequency divided by
 *the given divisor:
 *- Base frequencies:
 *  o The base frequency for pins 3, 9, 10, and 11 is 31250 Hz.
 *  o The base frequency for pins 5 and 6 is 62500 Hz.
 *- Divisors:
 *  o The divisors available on pins 5, 6, 9 and 10 are: 1, 8, 64,
 *    256, and 1024.
 *  o The divisors available on pins 3 and 11 are: 1, 8, 32, 64,
 *    128, 256, and 1024.
 *
 *-PWM frequencies are tied together in pairs of pins. If one in a
 *-pair is changed, the other is also changed to match:
 *- Pins 5 and 6 are paired on timer0
 *- Pins 9 and 10 are paired on timer1
 *- Pins 3 and 11 are paired on timer2
 *
 *-Note that this function will have side effects on anything else
 *-that uses timers:
 *- Changes on pins 3, 5, 6, or 11 may cause the delay() and
 *millis() functions to stop working. Other timing-related
 *functions may also be affected.
 *- Changes on pins 9 or 10 will cause the Servo library to function
 *incorrectly.
 *
 *-Thanks to macegr of the Arduino forums for his documentation of the
 *-PWM frequency divisors. His post can be viewed at:
 *@brief Divides a given PWM pin frequency by a divisor.
 *@param pin pin select
 *@param divisor select appropriate frequency divisor
 *@link https://forum.arduino.cc/index.php?topic=16612#msg121031
 *@return Void
 */

void IFX007TMotorControl::setPwmFrequency(int pin, int divisor)
{
	byte mode;
	if (pin == 5 || pin == 6 || pin == 9 || pin == 10)
	{
		switch (divisor)
		{
			case 1:
				mode = 0x01;
				break;
			case 8:
				mode = 0x02;
				break;
			case 64:
				mode = 0x03;
				break;
			case 256:
				mode = 0x04;
				break;
			case 1024:
				mode = 0x05;
				break;
			default:
				return;
		}

		if (pin == 5 || pin == 6)
		{
			TCCR0B = TCCR0B &0b11111000 | mode;
		}
		else
		{
			TCCR1B = TCCR1B &0b11111000 | mode;
		}
	}
	else if (pin == 3 || pin == 11)
	{
		switch (divisor)
		{
			case 1:
				mode = 0x01;
				break;
			case 8:
				mode = 0x02;
				break;
			case 32:
				mode = 0x03;
				break;
			case 64:
				mode = 0x04;
				break;
			case 128:
				mode = 0x05;
				break;
			case 256:
				mode = 0x06;
				break;
			case 1024:
				mode = 0x07;
				break;
			default:
				return;
		}

		TCCR2B = TCCR2B &0b11111000 | mode;
	}
}

/**
 *@brief To start generating PWM output at selected Pin
 *-U to start PWM at U pin
 *-V to start PWM at V pin
 *-W to start PWM at W pin
 *-# to start PWM for BLDC motor.
 *@param pwm_p pin to start PWM
 *@return Void
 */

void IFX007TMotorControl::start(char pwm_p)
{
	if (_isMotorReady)
	{
		if (pinParams_p1.pwm_pin == pwm_p && pwm_p == 'U')

		{
			if (!_ispwmactive_U)
			{
				analogWrite(_INU, pinParams_p1.dutyCycle);
				_ispwmactive_U = true;
			}
		}

		if (pinParams_p2.pwm_pin == pwm_p && pwm_p == 'V')

		{
			if (!_ispwmactive_V)
			{
				analogWrite(_INV, pinParams_p2.dutyCycle);
				_ispwmactive_V = true;
			}
		}

		if (pinParams_p3.pwm_pin == pwm_p && pwm_p == 'W')

		{
			if (!_ispwmactive_W)
			{
				analogWrite(_INW, pinParams_p3.dutyCycle);
				_ispwmactive_W = true;
			}
		}

		//// for bldc function
		if (pwm_p == '#' && pinParams_p1.pwm_pin == '#')
		{
			if (ClosedLoop == 0)
			{
				delayMicroseconds(OpenLoopDelay);
				commutate();
				updateHall();

			}
			else
			{
				commutate();
				while (oldHall == updateHall());
				HallCounts++;
			}

			if (Serial.available() > 0)
			{
				byte in = Serial.read();
				if (in == '+') RefRPM += 100;	//RefRPM + 100
				if (in == '-') RefRPM -= 100;	//RefRPM - 100

			}

			pI_Regulator_DoWork();

		}
	}
}

/**
 *@brief Rotate the motor 
 */

void IFX007TMotorControl::updateHardware(uint8_t CommutationStep)
{
	//run the motor 
	switch (CommutationStep)
	{
		case 1:
			digitalWrite(_INHU, HIGH);
			digitalWrite(_INHV, HIGH);
			digitalWrite(_INHW, LOW);
			analogWrite(_INU, bldcDutyCycle);
			analogWrite(_INV, 0);
			analogWrite(_INW, 0);
			break;

		case 2:
			digitalWrite(_INHU, HIGH);
			digitalWrite(_INHV, LOW);
			digitalWrite(_INHW, HIGH);
			analogWrite(_INU, bldcDutyCycle);
			analogWrite(_INV, 0);
			analogWrite(_INW, 0);
			break;

		case 3:
			digitalWrite(_INHU, LOW);
			digitalWrite(_INHV, HIGH);
			digitalWrite(_INHW, HIGH);
			analogWrite(_INU, 0);
			analogWrite(_INV, bldcDutyCycle);
			analogWrite(_INW, 0);
			break;

		case 4:
			digitalWrite(_INHU, HIGH);
			digitalWrite(_INHV, HIGH);
			digitalWrite(_INHW, LOW);
			analogWrite(_INU, 0);
			analogWrite(_INV, bldcDutyCycle);
			analogWrite(_INW, 0);
			break;

		case 5:
			digitalWrite(_INHU, HIGH);
			digitalWrite(_INHV, LOW);
			digitalWrite(_INHW, HIGH);
			analogWrite(_INU, 0);
			analogWrite(_INV, 0);
			analogWrite(_INW, bldcDutyCycle);
			break;

		case 6:
			digitalWrite(_INHU, LOW);
			digitalWrite(_INHV, HIGH);
			digitalWrite(_INHW, HIGH);
			analogWrite(_INU, 0);
			analogWrite(_INV, 0);
			analogWrite(_INW, bldcDutyCycle);
			break;

		default:
			break;
	}
}

/**
 *@brief Update the Hall Switch values
 */

uint8_t IFX007TMotorControl::updateHall()
{
	// to get the new position information of the motor and compared to the older one. every 10 ms
	oldHall = latestHall;
	latestHall = (digitalRead(A3) << 2) | (digitalRead(A2) << 1) | digitalRead(A1);
	if (OpenLoopSteps > 0)
	{
		if (oldHall != latestHall) OpenLoopSteps--;
		PI_Update_Timeout = millis() + 10;
	}
	else
	{
		ClosedLoop = 1;
	}

	return latestHall;
}

/**
 *@brief Commutation
 */

void IFX007TMotorControl::commutate()
{
	//the circulation of the motor
	updateHardware(CommutationState);
	CommutationState++;
	if (CommutationState == 7) CommutationState = 1;

}

/**
 *@brief PI controller implemented Every 10 ms. In the open loop used  to accelerate and in the closed loop used to eliminate the error.
 */

void IFX007TMotorControl::pI_Regulator_DoWork()
{
	//Do every 10 ms and in the open loop used  to accelerate and in the closed loop used to eliminate the error
	if (millis() > PI_Update_Timeout)
	{
		uint16_t RPM = (HallCounts *100 *60) / MotorPoles;
		LastRPM = RPM;
		float RPMf = (float) RPM;
		float Error = RefRPM - RPMf;
		PI_Integral = PI_Integral + Error;
		float pwm = PI_K *Error + PI_I * PI_Integral;
		//Limit PWM
		if (pwm > 200) pwm = 200;
		if (pwm < 30) pwm = 30;
		bldcDutyCycle = (uint8_t) pwm;
		HallCounts = 0;
		PI_Update_Timeout = millis() + 10;
	}
}

/**
 *@brief To stop generating PWM output at selected Pin
 *-U to stop PWM at U pin
 *-V to stop PWM at V pin
 *-W to stop PWM at W pin
 *-# to stop PWM for BLDC motor. 
 *@param Desired_PWM_PIN
 *@return Void 
 */

void IFX007TMotorControl::stop(char pwm_p)
{
	if (pwm_p == 'U')
	{
		digitalWrite(_INU, LOW);
		_ispwmactive_U = false;

	}

	if (pwm_p == 'V')
	{
		digitalWrite(_INV, LOW);
		_ispwmactive_V = false;

	}

	if (pwm_p == 'W')
	{
		digitalWrite(_INW, LOW);
		_ispwmactive_W = false;

	}

	if (pwm_p == '#')
	{
		digitalWrite(_INU, LOW);
		digitalWrite(_INV, LOW);
		digitalWrite(_INW, LOW);

	}
}

/**
 *@brief Begin will allow Motor Shield control pin initilalization
 */

void IFX007TMotorControl::end()
{
	digitalWrite(_INU, LOW);
	digitalWrite(_INV, LOW);
	digitalWrite(_INW, LOW);
	_isMotorReady = false;

}