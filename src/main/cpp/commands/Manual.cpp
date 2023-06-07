// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Manual.h"

Manual::Manual(Arm* arm, frc::XboxController* stick)
  : m_arm{arm}, m_stick{stick}
{
  // Register that this command requires the subsystem.
  AddRequirements(m_arm);
}


void Manual::Initialize() {}

void Manual::Execute()
{
  if(!m_arm->is_loaded())
  {
    m_arm->move(CONSTANTS::ARM::INTAKE_POS);
    m_arm->spin(-CONSTANTS::ROLLER::VELOCITY);
  }
  else
  {
    m_arm->move(CONSTANTS::ARM::STORE_POS);
  }
}

bool Manual::IsFinished()
{
  return (m_arm->is_loaded());
}

