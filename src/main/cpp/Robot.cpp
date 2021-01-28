#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() 
{
    m_scheduler = &frc2::CommandScheduler::GetInstance();
    m_scheduler->RegisterSubsystem(m_container.GetDriveSubsystem());
    m_scheduler->SetDefaultCommand(m_container.GetDriveSubsystem(), *(m_container.GetDriveCommand()));
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() 
{
    m_scheduler->Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() 
{

}

void Robot::DisabledPeriodic() 
{

}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() 
{
    m_autonomous_command = m_container.GetAutonomousCommand();

    if (m_autonomous_command != nullptr) 
    {
        m_autonomous_command->Schedule();
    }
}

void Robot::AutonomousPeriodic() 
{

}

void Robot::TeleopInit() 
{
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (m_autonomous_command != nullptr) 
    {
        m_autonomous_command->Cancel();
        m_autonomous_command = nullptr;
    }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() 
{

}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() 
{

}

#ifndef RUNNING_FRC_TESTS
int main() 
{
    return frc::StartRobot<Robot>();
}
#endif
