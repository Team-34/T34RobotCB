#include <memory>
#include <frc/smartdashboard/SmartDashboard.h>

#include "subsystems/SwerveMath.h"
#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() 
    : m_lf(SwerveModule("Left_Front", ID_LEFT_FWD_DRIVE, ID_LEFT_FWD_STEER, -1.0))
    , m_la(SwerveModule("Left Back", ID_LEFT_AFT_DRIVE, ID_LEFT_AFT_STEER, -1.0))
    , m_rf(SwerveModule("Right_Front", ID_RIGHT_FWD_DRIVE, ID_RIGHT_FWD_STEER))
    , m_ra(SwerveModule("Right_Back", ID_RIGHT_AFT_DRIVE, ID_RIGHT_AFT_STEER))
    , m_db(0.1)
    , m_speed(1.0)
{
    m_gyro = new AHRS(frc::SPI::Port::kMXP);
    m_mode = DriveMode::RobotCentric;
}


void DriveSubsystem::Periodic() 
{
  // Implementation of subsystem periodic method goes here.
}

void DriveSubsystem::SimulationPeriodic() 
{
  // Implementation of subsystem simulation periodic method goes here.
}

void DriveSubsystem::Drive(double x, double y, double r)
{
    //Deadband
    if (fabs(x) < m_db && fabs(y) < m_db && fabs(r) < m_db)
    {
        m_lf.SetDriveSpeed(0.0);
        m_la.SetDriveSpeed(0.0);
        m_rf.SetDriveSpeed(0.0);
        m_ra.SetDriveSpeed(0.0);        
        return;
    }

    x *= -1;
    y *= -1;

    
    if (m_mode == DriveMode::FieldOriented && m_gyro != nullptr)
    {   
        double gyro_radians = deg_to_rad(m_gyro->GetYaw());
        double temp_y = y * cos(gyro_radians) + x * sin(gyro_radians);
        x = -y * sin(gyro_radians) + x * cos(gyro_radians);
        y = temp_y;       
    }
    
    double a = (x - r) * FRAME_LENGTH_DIV_RATIO();
    double b = (x + r) * FRAME_LENGTH_DIV_RATIO();
    double c = (y - r) * FRAME_WIDTH_DIV_RATIO();
    double d = (y + r) * FRAME_WIDTH_DIV_RATIO();

    m_lf.SetSteerPosition(rad_to_deg(atan2(b, c)));
    m_la.SetSteerPosition(rad_to_deg(atan2(a, c)));
    m_rf.SetSteerPosition(rad_to_deg(atan2(b, d)));
    m_ra.SetSteerPosition(rad_to_deg(atan2(a, d)));


    double lf_drive_output = sqrt(sqr(b) + sqr(c)); 
    double la_drive_output = sqrt(sqr(a) + sqr(c)); 
    double rf_drive_output = sqrt(sqr(b) + sqr(d)); 
    double ra_drive_output = sqrt(sqr(a) + sqr(d)); 

    double do_max = std::max(std::initializer_list<double>(
        {lf_drive_output, la_drive_output, rf_drive_output, ra_drive_output}));

    if (do_max > 1.0)
    {
        lf_drive_output /= do_max;
        la_drive_output /= do_max;
        rf_drive_output /= do_max;
        ra_drive_output /= do_max;
    }

    m_lf.SetDriveSpeed(lf_drive_output * m_speed);
    m_la.SetDriveSpeed(la_drive_output * m_speed);
    m_rf.SetDriveSpeed(rf_drive_output * m_speed);
    m_ra.SetDriveSpeed(ra_drive_output * m_speed);
}

void DriveSubsystem::ShieldWall()
{
    m_lf.SetDriveSpeed(0.0);
    m_la.SetDriveSpeed(0.0);
    m_rf.SetDriveSpeed(0.0);
    m_ra.SetDriveSpeed(0.0);

    m_lf.SetSteerPosition(_315_DEG);
    m_la.SetSteerPosition(_135_DEG);
    m_rf.SetSteerPosition(_135_DEG);
    m_ra.SetSteerPosition(_315_DEG);
}

void DriveSubsystem::SetSteerPosition(double lf, double rf, double la, double ra)
{
    m_lf.SetSteerPosition(lf);
    m_la.SetSteerPosition(la);
    m_rf.SetSteerPosition(rf);
    m_ra.SetSteerPosition(ra);
}

void DriveSubsystem::SetDriveSpeed(double speed)
{
    m_lf.SetDriveSpeed(speed);
    m_la.SetDriveSpeed(speed);
    m_rf.SetDriveSpeed(speed);
    m_ra.SetDriveSpeed(speed);
}
