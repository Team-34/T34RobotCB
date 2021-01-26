// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutonomousCommand.h"

AutonomousCommand::AutonomousCommand(DriveSubsystem* subsystem)
    : m_drive_subsystem{subsystem} 
    , m_finished(false)
{

}

void AutonomousCommand::Initialize()
{

}

void AutonomousCommand::Execute()
{

}

void AutonomousCommand::End(bool interrupted)
{

}

bool AutonomousCommand::IsFinished()
{
    return m_finished;
}

bool AutonomousCommand::HasRequirement(frc2::Subsystem* requirement) const 
{
    if (requirement == m_drive_subsystem)
        return true;

    return false;
}