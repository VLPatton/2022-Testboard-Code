/****************************************************************************
	Description:	Defines the CDrive control class.
	Classes:		CDrive
	Project:		2022 Testboard Robot Code
****************************************************************************/
#ifndef Drive_h
#define Drive_h

#include "IOMap.h"
#include "SparkMotion.h"

#include "AHRS.h"
#include "rev/CANSparkMax.h"
#include <frc/controller/PIDController.h>
#include <frc/AnalogInput.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc2/command/RamseteCommand.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/geometry/Pose2d.h>

using namespace rev;
using namespace frc;
using namespace units;

// Declare constants
const double dMotorOpenLoopRampRate				= 0.650;
const double dJoystickDeadzone					= 0.100;
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
    Description:	CDrive class definition.
    Arguments:		None
    Derived From:	Nothing
******************************************************************************/
class CDrive
{
public:
	// Declare class methods.
	CDrive(Joystick *pDriveController);
	~CDrive();
	void Init();
	void Tick();
	void ResetOdometry();
	void SetJoystickControl(bool bJoystickControl);

private:
	// Declare class objects and variables.
	bool									m_bJoystickControl;
	CSparkMotion*							m_pDriveMotor1;
	CSparkMotion*							m_pDriveMotor2;
	AHRS*									m_pGyro;
	Joystick*								m_pDriveController;
	DifferentialDrive*						m_pRobotDrive;
	//DifferentialDriveOdometry*				m_pOdometry;
	//Trajectory								m_Trajectory;
};
///////////////////////////////////////////////////////////////////////////////
#endif