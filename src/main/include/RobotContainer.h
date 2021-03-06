#pragma once

#include <frc2/command/Command.h>
#include "utils/T34_XboxController.h"
#include "commands/DriveCommand.h"
#include "subsystems/DriveSubsystem.h"
#include "commands/AutonomousCommand.h"
#include "commands/DriveToDistance.h"


class RobotContainer 
{
public:
    RobotContainer();

    // Methods for getting Commands
    frc2::Command* GetAutonomousCommand();
    DriveCommand* GetDriveCommand();

    // Methods for getting Subsystems
    DriveSubsystem* GetDriveSubsystem();
    
    // Methods for getting Input Devices and Sensors
    T34_XboxController* GetDriveController();

private:
    // Subsystem declarations
    DriveSubsystem m_drive_subsystem;
    
    // Command declarations
    //AutonomousCommand m_autonomous_command;
    DriveToDistanceCMD m_autonomous_command;
    DriveCommand m_drive_command;

    // Input Devices and Sensor declarations;
    T34_XboxController  m_drive_ctrl;

private:
    // Internal methods
    void ConfigureButtonBindings();
};
