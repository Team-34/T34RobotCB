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
class DriveCommand
  : public frc2::CommandHelper<frc2::CommandBase, DriveCommand>
{
public:
    /**
     * Creates a new DriveCommand.
     *
     * @param subsystem The subsystem used by this command.
     */
    explicit DriveCommand(DriveSubsystem* subsystem);

    void Initialize() override;
    void Execute() override;
    void End(bool interrupted) override;
    bool IsFinished() override;

    bool HasRequirement(frc2::Subsystem *requirement) const;
    wpi::SmallSet<frc2::Subsystem*, 4> GetRequirements() const { return m_requirements; }

private:
    DriveSubsystem* m_drive_subsystem;
    wpi::SmallSet<frc2::Subsystem*, 4> m_requirements;
};
