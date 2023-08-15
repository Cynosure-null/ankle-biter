// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "subsystems/Arm.h"
#include <frc/XboxController.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/button/CommandXboxController.h>

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Manual : public frc2::CommandHelper<frc2::CommandBase, Manual>
{
  public:
    explicit Manual(Arm *arm, frc2::CommandXboxController *stick);

    void Execute() override;

    void Initialize() override;

  private:
    Arm *m_arm;

    frc2::CommandXboxController *m_stick;

    double setpoint;
};
