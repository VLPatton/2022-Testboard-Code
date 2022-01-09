/****************************************************************************
    Description:	Defines the RobotMain class.
    Classes:		CRobotMain
    Project:		2022 Testboard Robot Code
****************************************************************************/
#pragma once

#include "Drive.h"
#include "AuxAttachment.h"

#include <string>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Joystick.h>

using namespace frc;
using namespace std;
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
    Description:	CRobotMain class definition.
    Arguments:		None
    Derived From:	TimedRobot
******************************************************************************/
class CRobotMain : public TimedRobot 
{
public:
	// Declare class methods.
	CRobotMain();
	~CRobotMain();
	void RobotInit() override;
	void RobotPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void TestInit() override;
	void TestPeriodic() override;

private:
	// Declare objects and variables.
	CDrive*							m_pDrive;
	CAuxAttachment*					m_pAuxAttachment;
	SendableChooser<string>*		m_pAutonomousChooser;
	string							m_strAutoSelected;
	Joystick*						m_pJoystick;
};
