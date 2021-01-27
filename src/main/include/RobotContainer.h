// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>
#include "utils/T34_XboxController.h"
#include "commands/DriveCommand.h"
#include "commands/AutonomousCommand.h"
#include "subsystems/DriveSubsystem.h"
#include "commands/ShieldWallCommand.h"
/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer 
{
public:
    RobotContainer();

    frc2::Command* GetAutonomousCommand();

    DriveSubsystem& GetDriveSubsystem();
    DriveCommand& GetDriveCommand();
    ShieldWallCommand& GetShieldWallCommand();
    T34_XboxController& GetDriveController() { return m_driver; }
    frc2::JoystickButton& GetButtonB() { return m_b_button; }

private:
    // The robot's subsystems and commands are defined here...
    DriveSubsystem m_drive_subsystem;
    DriveCommand m_drive_command;

    AutonomousCommand m_autonomous_command;
    ShieldWallCommand m_shield_wall_command;
    T34_XboxController  m_driver;


    frc2::JoystickButton m_b_button;

    void ConfigureButtonBindings();


};
