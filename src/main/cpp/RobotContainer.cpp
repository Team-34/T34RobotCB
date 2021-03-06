#include "RobotContainer.h"
#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() 
    : m_drive_command(&m_drive_subsystem) 
    , m_autonomous_command(&m_drive_subsystem, 0.3, 0.0, 60.0) 
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
                } ,
                std::initializer_list< frc2::Subsystem * >{ &m_drive_subsystem }
            }            
        );
    
    // Bind Driver Controller A Button Released Event to Toggle Mode
    frc2::JoystickButton(&m_drive_ctrl, XBC_Button::A)
        .WhenReleased(
            frc2::InstantCommand
            {
                [this]
                { 
                    m_drive_subsystem.ToggleMode();
                } 
            }            
        );
    
     // Bind Driver Controller Back Button Released Event to ZeroYaw
    frc2::JoystickButton(&m_drive_ctrl, XBC_Button::Back)
        .WhenReleased(
            frc2::InstantCommand
            {
                [this]
                { 
                    m_drive_subsystem.ZeroYaw();
                } 
            }            
        );
}