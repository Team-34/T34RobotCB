// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() 
    : m_autonomous_command(&m_drive_subsystem) 
    , m_drive_command(&m_drive_subsystem)
    , m_shield_wall_command(&m_drive_subsystem)
    , m_driver(ID_DRIVE_CONTROLLER)
    , m_b_button(&m_driver, 2)
{
  //  m_driver.reset(new T34_XboxController(ID_DRIVE_CONTROLLER));
   // m_b_button = frc2::JoystickButton(m_driver.get(), 2);
    // Initialize all of your commands and subsystems here

    // Configure the button bindings
    ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() 
{
    // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
    // An example command will be run in autonomous
    return &m_autonomous_command;
}

DriveSubsystem& RobotContainer::GetDriveSubsystem()
{
    return m_drive_subsystem;
}

DriveCommand& RobotContainer::GetDriveCommand()
{
    return m_drive_command;
}

ShieldWallCommand& RobotContainer::GetShieldWallCommand()
{
    return m_shield_wall_command;

}