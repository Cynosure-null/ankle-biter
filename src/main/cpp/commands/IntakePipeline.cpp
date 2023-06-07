// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakePipeline.h"

IntakePipeline::IntakePipeline(Arm* arm)
  : m_arm{arm} {
  // Register that this command requires the subsystem.
  AddRequirements(m_arm);
}


void IntakePipeline::Initialize() {}

void IntakePipeline::Execute()
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

bool IntakePipeline::IsFinished()
{
  return (m_arm->is_loaded());
}

