#include "RobotContainer.h"
#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() 
    : m_autonomous_command(&m_drive_subsystem) 
    , m_drive_command(&m_drive_subsystem)
    , m_drive_ctrl(ID_DRIVE_CONTROLLER)
{
    // Configure the button bindings
    ConfigureButtonBindings();
}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
    return &m_autonomous_command;
}

DriveSubsystem* RobotContainer::GetDriveSubsystem()
{
    return &m_drive_subsystem;
}

DriveCommand* RobotContainer::GetDriveCommand()
{
    return &m_drive_command;
}

T34_XboxController* RobotContainer::GetDriveController()
{
    return &m_drive_ctrl;
}

void RobotContainer::ConfigureButtonBindings() 
{
    
    // Bind Driver Controller B Button Pressed Event to ShieldWall
    frc2::JoystickButton(&m_drive_ctrl, XBC_Button::B)
        .WhenPressed(
            frc2::InstantCommand
            {
                [this]
                { 
                    m_drive_subsystem.ShieldWall();
                } 
            }            
        );
}