// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <AHRS.h>

#include "constants.h"
#include "subsystems/SwerveModule.h"

#include <frc2/command/SubsystemBase.h>

enum class DriveMode
{
    RobotCentric,
    FieldOriented
};

class DriveSubsystem : public frc2::SubsystemBase 
{
public:
    DriveSubsystem();

    /**
     * Will be called periodically whenever the CommandScheduler runs.
     */
    void Periodic() override;

    /**
     * Will be called periodically whenever the CommandScheduler runs during
     * simulation.
     */
    void SimulationPeriodic() override;

    void Drive(double x, double y, double r);

    void SetSteerPosition(double lf, double rf, double la, double ra);
    void SetDriveSpeed(double speed);

private:
    AHRS * m_gyro;
    DriveMode m_mode;
    
    SwerveModule m_lf;
    SwerveModule m_la;
    SwerveModule m_rf;
    SwerveModule m_ra;
    double m_db;
    double m_speed;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
