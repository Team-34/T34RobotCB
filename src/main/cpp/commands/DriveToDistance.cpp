// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"
#include "commands/DriveToDistance.h"
#include "subsystems/SwerveMath.h"
#include <frc/smartdashboard/SmartDashboard.h>

DriveToDistanceCMD::DriveToDistanceCMD(DriveSubsystem* subsystem, double speed, double angle, double distance)
    : m_drive_subsystem{subsystem} 
    , m_finished(false)
    , m_speed(speed)
    , m_angle(angle)
    , m_distance(distance)
    , m_encoder_position(0.0)
{
    m_requirements.insert(m_drive_subsystem);

}

void DriveToDistanceCMD::Initialize()
{
    m_distance = fabs(m_distance / FULL_ROTATION * 20480.0);
    frc::SmartDashboard::PutNumber("Drive distance",m_distance);
    m_drive_subsystem->ZeroDrivePosition();
    //m_encoder_position = fabs(m_drive_subsystem->GetDrivePosition());
    //frc::SmartDashboard::PutNumber("start position",m_encoder_position);
    m_drive_subsystem->SetSteerPosition(m_angle, m_angle, m_angle, m_angle);

    m_drive_subsystem->SetDriveTarget(-m_distance);

    double p = frc::SmartDashboard::GetNumber("p" , 0.0047);
    double i = frc::SmartDashboard::GetNumber("i" , 0.000000005);
    double d = frc::SmartDashboard::GetNumber("d" , 0.045);
    m_drive_subsystem->SetDrivePID(p, i, d);
}

void DriveToDistanceCMD::Execute()
{
    double position = fabs(m_drive_subsystem->GetDrivePosition());
        frc::SmartDashboard::PutNumber("current position", position);
    if (m_distance + 1000.0 < position && m_distance - 1000.0 > position)
    {
        m_finished = true;
        m_drive_subsystem->SetFollowMode(false);
    }
    
    frc::SmartDashboard::PutNumber("delta", m_distance - m_drive_subsystem->GetDrivePosition());
    frc::SmartDashboard::PutNumber("delta2", m_distance + m_drive_subsystem->GetDrivePosition());
}

void DriveToDistanceCMD::End(bool interrupted)
{
    

}

bool DriveToDistanceCMD::IsFinished()
{
    return m_finished;
}

bool DriveToDistanceCMD::HasRequirement(frc2::Subsystem* requirement) const 
{
    if (requirement == m_drive_subsystem)
        return true;

    return false;
}
