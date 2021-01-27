// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShieldWallCommand.h"
#include "subsystems/SwerveMath.h"

ShieldWallCommand::ShieldWallCommand(DriveSubsystem* subsystem)
    : m_drive_subsystem{subsystem} 
    , m_finished(false)
{
    m_requirements.insert(m_drive_subsystem);
}

void ShieldWallCommand::Initialize()
{

}

void ShieldWallCommand::Execute()
{
    m_drive_subsystem->SetDriveSpeed(0.0);
    m_drive_subsystem->SetSteerPosition(_315_DEG, _135_DEG, _135_DEG, _315_DEG);
    m_finished = true;
}

void ShieldWallCommand::End(bool interrupted)
{

}

bool ShieldWallCommand::IsFinished()
{
    return m_finished;
}

bool ShieldWallCommand::HasRequirement(frc2::Subsystem* requirement) const 
{
    if (requirement == m_drive_subsystem)
        return true;

    return false;
}