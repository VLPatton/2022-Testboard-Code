/****************************************************************************
	Description:	Defines the CAuxAttachment control class.
	Classes:		CAuxAttachment
	Project:		2022 Testboard Robot Code
****************************************************************************/
#ifndef AuxAttachment_h
#define AuxAttachment_h

#include "IOMap.h"
#include "Drive.h"

#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>

using namespace ctre;
using namespace rev;
using namespace frc;
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
	Description:	CAuxAttachment class definition.
	Arguments:		None
	Derived From:	Nothing
******************************************************************************/
class CAuxAttachment
{
public:
	// Declare class methods.
	CAuxAttachment(Joystick* pJoystick);
	~CAuxAttachment();
	void	Init();
	void	Tick();
	void	Activate550OnSwitch();
	bool	ReadOpticalSensor();
	void	SetJoystickControl(bool bJoystickControl);

private:
	// Declare class objects and variables.
	CANSparkMax*                            m_pAuxMotor1;       // NEO 550
	WPI_TalonFX*                            m_pAuxMotor2;       // Falcon 500
	WPI_TalonSRX*                           m_pAuxMotor3;       // BAG Motor
	Solenoid*                               m_pActuator1;
	Joystick*                               m_pJoystick;
	DigitalInput*							m_pOpticalSensor;	// Optical beam-break sensor on DIO 0
	DigitalInput*							m_pLimitSwitchNC;

	bool                                    m_bJoystickControl;	// Variable for Joystick control.
};
///////////////////////////////////////////////////////////////////////////////
#endif