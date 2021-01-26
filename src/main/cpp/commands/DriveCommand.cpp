// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubsystem* subsystem)
    : m_drive_subsystem{subsystem} 
{
    m_requirements.insert(m_drive_subsystem);
}

void DriveCommand::Initialize()
{

}

void DriveCommand::Execute()
{

}

void DriveCommand::End(bool interrupted)
{

}

bool DriveCommand::IsFinished()
{
    return false;
}

bool DriveCommand::HasRequirement(frc2::Subsystem* requirement) const 
{
    if (requirement == m_drive_subsystem)
        return true;

    return false;
}

