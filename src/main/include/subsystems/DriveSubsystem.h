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
    void ShieldWall();
    void SetSteerPosition(double lf, double rf, double la, double ra);
    void SetDriveSpeed(double speed);
    inline void ZeroDrivePosition() { m_lf.ZeroDrivePosition(); }
    double GetDrivePosition();

private:
    AHRS * m_gyro;
    DriveMode m_mode;
    
    SwerveModule m_lf;
    SwerveModule m_la;
    SwerveModule m_rf;
    SwerveModule m_ra;
    double m_db;
    double m_speed;
};
