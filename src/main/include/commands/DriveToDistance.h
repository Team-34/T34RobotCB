// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"

/**
 * Drive command that uses an Drive subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DriveToDistanceCMD
  : public frc2::CommandHelper<frc2::CommandBase, DriveToDistanceCMD>
{
public:
    /**
     * Creates a new DriveCommand.
     *
     * @param subsystem The subsystem used by this command.
     */
    explicit DriveToDistanceCMD(DriveSubsystem* subsystem, double speed, double angle, double distance);

    void Initialize() override;
    void Execute() override;
    void End(bool interrupted) override;
    bool IsFinished() override;

    bool HasRequirement(frc2::Subsystem *requirement) const;

private:
    bool m_finished;
    DriveSubsystem* m_drive_subsystem;
    double m_encoder_position;
    double m_speed;
    double m_angle;
    double m_distance;

};
