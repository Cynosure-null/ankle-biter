// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/HoldMode.h"
#include "frc/smartdashboard/SmartDashboard.h"

HoldMode::HoldMode(Arm *arm) : m_arm{ arm }
{
  // Register that this command requires the subsystem.
  AddRequirements(m_arm);
}

void HoldMode::Initialize()
{
  std::cout << "hold.init \n";
  holdpoint = m_arm->get_position();
}

void HoldMode::Execute()
{
  std::cout << "hold.execute \n";
  m_arm->move(holdpoint);
  frc::SmartDashboard::PutNumber("holdpt", holdpoint);
}

void HoldMode::End(bool interrupted)
{
  std::cout << "hold.end \n";
  holdpoint = CONSTANTS::ARM::STORE_POS;
}
