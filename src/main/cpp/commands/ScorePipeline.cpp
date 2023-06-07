// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ScorePipeline.h"

ScorePipeline::ScorePipeline(Arm* arm)
  : m_arm{arm} {
  // Register that this command requires the subsystem.
  AddRequirements(m_arm);
}


void ScorePipeline::Initialize() {}

void ScorePipeline::Execute()
{
  if( (m_arm->get_position() >= CONSTANTS::ARM::SCORE_POS * 0.98) &&
      (m_arm->get_position() <= CONSTANTS::ARM::SCORE_POS * 1.02))
  {
    m_arm->move(CONSTANTS::ARM::SCORE_POS);
  }
  else
  {
    m_arm->spin(CONSTANTS::ROLLER::VELOCITY);
  }
}

bool ScorePipeline::IsFinished()
{
  return (!m_arm->is_loaded());
}

