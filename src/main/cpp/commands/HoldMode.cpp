// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/HoldMode.h"

HoldMode::HoldMode(Arm* arm)
  : m_arm{arm}
{
  // Register that this command requires the subsystem.
  AddRequirements(m_arm);
}


void HoldMode::Initialize()
{
  holdpoint = m_arm->get_position();
}

void HoldMode::Execute()
{
  m_arm->move(holdpoint);
}

bool HoldMode::End()
{
  holdpoint = CONSTANTS::ARM::STORE_POS;
}
