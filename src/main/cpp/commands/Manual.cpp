// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Manual.h"
#include "frc/smartdashboard/SmartDashboard.h"


Manual::Manual(Arm *arm, frc2::CommandXboxController *stick)
    : m_arm{ arm }, m_stick{ stick }
{
  // Register that this command requires the subsystem.
  AddRequirements(m_arm);
}

void
Manual::Initialize()
{
  std::cout << "Manual.init"
            << "\n";
  setpoint = m_arm->get_position();
}

void
Manual::Execute()
{
  frc::SmartDashboard::PutString("cmd", "Manual");
  std::cout << "Manual.execute"
            << "\n";
  m_arm->move(setpoint);

  if(m_stick->GetLeftTriggerAxis() > 0.3)
  {
    setpoint -= CONSTANTS::ARM::STEP;
  }
  if(m_stick->GetRightTriggerAxis() > 0.3)
  {
    setpoint += CONSTANTS::ARM::STEP;
  }
}
