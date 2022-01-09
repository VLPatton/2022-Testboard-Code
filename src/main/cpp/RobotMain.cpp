/******************************************************************************
	Description:	2021 Infinite Recharge Robot Control Software.
	Classes:		CRobotMain
	Project:		2022 Test Board Code
******************************************************************************/
#include "RobotMain.h"

#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
	Description:	CRobotMain Constructor.
	Arguments:		None
	Derived From:	TimedRobot
******************************************************************************/
CRobotMain::CRobotMain()
{
	// Initialize objects and variables.
	m_pJoystick						= new Joystick(0);
	m_pDrive						= new CDrive(m_pJoystick);
	m_pAuxAttachment				= new CAuxAttachment(m_pJoystick);
	m_pAutonomousChooser			= new SendableChooser<string>();
}

/******************************************************************************
	Description:	CRobotMain Destructor.
	Arguments:		None
	Derived From:	TimedRobot
******************************************************************************/
CRobotMain::~CRobotMain()
{
	delete m_pJoystick;
	delete m_pDrive;
	delete m_pAuxAttachment;
	delete m_pAutonomousChooser;

	m_pJoystick						= nullptr;
	m_pDrive						= nullptr;
	m_pAuxAttachment				= nullptr;
	m_pAutonomousChooser			= nullptr;
}

/****************************************************************************
	Description:	Ran on initial startup of the robot.
	Arguments: 		None
	Returns:		Nothing
****************************************************************************/
void CRobotMain::RobotInit() 
{
	// Setup autonomous chooser.
	m_pAutonomousChooser->SetDefaultOption("Autonomous Idle", "Autonomous Idle");
	m_pAutonomousChooser->AddOption("Alliance Trench", "Alliance Trench");
	m_pAutonomousChooser->AddOption("Front Shield Generator", "Front Shield Generator");
	m_pAutonomousChooser->AddOption("Side Shield Generator", "Side Sheild Generator");
	m_pAutonomousChooser->AddOption("Opposing Trench", "Opposing Trench");
	m_pAutonomousChooser->AddOption("Power Port", "Power Port");
	m_pAutonomousChooser->AddOption("Test Path", "Test Path");
	SmartDashboard::PutData(m_pAutonomousChooser);
}

/******************************************************************************
	Description:	Runs every 20ms in a loop after the robot has started.
	Arguments:	 	None
	Returns:		Nothing
******************************************************************************/
void CRobotMain::RobotPeriodic()
{
	
}

/******************************************************************************
	Description:	Ran only once, after the robot has entered Autonomous mode.
	Arguments:	 	None
	Returns:		Nothing
******************************************************************************/
void CRobotMain::AutonomousInit() 
{
	m_pDrive->Init();
	m_pDrive->SetJoystickControl(false);
	m_pAuxAttachment->Init();
	m_pAuxAttachment->SetJoystickControl(false);
}

/******************************************************************************
	Description:	Runs every 20ms in a loop after the robot has entered
					Autonomous mode.
	Arguments:	 	None
	Returns:		Nothing
******************************************************************************/
void CRobotMain::AutonomousPeriodic() 
{

}

/******************************************************************************
	Description:	Ran only once, after the robot has entered Teleop mode.
	Arguments:	 	None
	Returns:		Nothing
******************************************************************************/
void CRobotMain::TeleopInit()
{
	// Initialize classes.
	m_pDrive->Init();
	m_pDrive->SetJoystickControl(true);
	m_pAuxAttachment->Init();
	m_pAuxAttachment->SetJoystickControl(true);
}

/******************************************************************************
	Description:	Runs every 20ms in a loop after the robot has entered
					Teleop mode.
	Arguments:	 	None
	Returns:		Nothing
******************************************************************************/
void CRobotMain::TeleopPeriodic()
{
	m_pDrive->Tick();
	m_pAuxAttachment->Tick();
	m_pAuxAttachment->Activate550OnSwitch();
}

/******************************************************************************
	Description:	Ran only once, after the robot has entered Disabled mode.
	Arguments:	 	None
	Returns:		Nothing
******************************************************************************/
void CRobotMain::DisabledInit()
{
	m_pDrive->SetJoystickControl(false);
	m_pAuxAttachment->SetJoystickControl(false);
}

/******************************************************************************
	Description:	Runs every 20ms in a loop after the robot has entered
					Teleop mode.
	Arguments:	 	None
	Returns:		Nothing
******************************************************************************/
void CRobotMain::DisabledPeriodic()
{

}

/******************************************************************************
	Description:	Ran only once, after the robot has entered Test mode.
	Arguments:	 	None
	Returns:		Nothing
******************************************************************************/
void CRobotMain::TestInit() 
{
	m_pDrive->Init();
	m_pAuxAttachment->Init();
	m_pDrive->SetJoystickControl(true);
	m_pAuxAttachment->SetJoystickControl(true);
}

/******************************************************************************
	Description:	Runs every 20ms in a loop after the robot has entered
					Test mode.
	Arguments:	 	None
	Returns:		Nothing
******************************************************************************/
void CRobotMain::TestPeriodic()
{
	// Tick Drive and AuxAttachment
	m_pDrive->Tick();
	m_pAuxAttachment->Tick();
	m_pAuxAttachment->Activate550OnSwitch();
	cout << m_pAuxAttachment->ReadOpticalSensor() << "\n";
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return StartRobot<CRobotMain>();
}
#endif
