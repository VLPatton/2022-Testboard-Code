/****************************************************************************
	Description:	Implements the CAuxAttachment control class.
	Classes:		CAuxAttachment
	Project:		2022 Testboard Robot Code
****************************************************************************/
#include "AuxAttachment.h"
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
	Description:	CAuxAttachment Constructor.
	Arguments:		Joystick* pJoystick - pointer to Joystick object.
	Derived From:	Nothing
******************************************************************************/
CAuxAttachment::CAuxAttachment(Joystick* pJoystick)
{
	m_pAuxMotor1			= new CANSparkMax(nAuxMotor1, CANSparkMax::MotorType::kBrushless);
	m_pAuxMotor2			= new WPI_TalonFX(nAuxMotor2);
	m_pAuxMotor3			= new WPI_TalonSRX(nAuxMotor3);

	m_pLimitSwitchNC		= new DigitalInput(nLimitSwitchNC);
	m_pOpticalSensor		= new DigitalInput(nOpticalSensor);

	// Init Joystick.
	m_pJoystick				= pJoystick;
	m_bJoystickControl		= false;
}

/******************************************************************************
	Description:	CAuxAttachment Destructor.
	Arguments:		None
	Derived From:	Nothing
******************************************************************************/
CAuxAttachment::~CAuxAttachment()
{
	// Delete pointers
	delete m_pAuxMotor1;
	delete m_pAuxMotor2;
	delete m_pAuxMotor3;
	delete m_pLimitSwitchNC;
	delete m_pOpticalSensor;

	// Set to nullptr's
	m_pAuxMotor1		= nullptr;
	m_pAuxMotor2		= nullptr;
	m_pAuxMotor3		= nullptr;
	m_pLimitSwitchNC	= nullptr;
	m_pOpticalSensor	= nullptr;
}

/******************************************************************************
	Description:	Initializes the AuxAttachment class.
	Arguments:		None
	Returns:	    Nothing
******************************************************************************/
void CAuxAttachment::Init()
{
	// Set max acceleration to .65 seconds and clear faults
	m_pAuxMotor1->SetOpenLoopRampRate(dMotorOpenLoopRampRate);	// NEO 550
	m_pAuxMotor1->ClearFaults();

	m_pAuxMotor2->ConfigOpenloopRamp(dMotorOpenLoopRampRate);	// Falcon500
	m_pAuxMotor2->ClearStickyFaults();

	m_pAuxMotor3->ConfigOpenloopRamp(dMotorOpenLoopRampRate);	// BAG motor
	m_pAuxMotor3->ClearStickyFaults();
}

/******************************************************************************
	Description:	Update periodic functions, ran every 20ms.
	Arguments:		None
	Returns:	    Nothing
******************************************************************************/
void CAuxAttachment::Tick()
{
	if (m_bJoystickControl) {
		if (m_pJoystick->GetRawButtonPressed(eButtonA)) {
			m_pAuxMotor2->Set(m_pJoystick->GetRawAxis(eRightTrigger));	// If button A is pressed, set speed to the amount read on Right Trigger axis
		}
		if (m_pJoystick->GetRawButtonReleased(eButtonA)) {
			m_pAuxMotor2->Set((double)0);								// If button A is released, set speed to 0%
		}
	}
}

/******************************************************************************
	Description:	Get the states of the two lim. sw. inputs and return in an
					integer pointer
	Arguments:		None
	Returns:	    Nothing
******************************************************************************/
void CAuxAttachment::Activate550OnSwitch()
{
	// if the Normally Closed (low) part of the switch is high, set NEO 550 
	// to half speed; else, set it to 0 
	if (m_pLimitSwitchNC->Get()) {
		m_pAuxMotor1->Set(0.500);
	} else {
		m_pAuxMotor1->Set(0.000);
	}

}

/******************************************************************************
	Description:	Get the states of the two lim. sw. inputs and return in an
					integer pointer
	Arguments:		None
	Returns:	    m_pOpticalSensor->Get()
******************************************************************************/
bool CAuxAttachment::ReadOpticalSensor()
{
	return m_pOpticalSensor->Get();
}

/******************************************************************************
	Description:	Set m_bJoystickControl to true or false
	Arguments:		bJoystickControl - value to set m_bJoystickControl
	Returns:	    Nothing
******************************************************************************/
void CAuxAttachment::SetJoystickControl(bool bJoystickControl)
{
	m_bJoystickControl = bJoystickControl;
}