// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakePipeline.h"
#include "frc/smartdashboard/SmartDashboard.h"

IntakePipeline::IntakePipeline(Arm* arm)
  : m_arm{arm} {
  // Register that this command requires the subsystem.
  AddRequirements(m_arm);
}


void IntakePipeline::Initialize() {}

void IntakePipeline::Execute()
{
  frc::SmartDashboard::PutString("cmd", "IntakePipeline");
  //char buff[strlen((char[])__DBL_MAX__)]; //Probably big enough
  char* buff = (char*)malloc(sizeof(char)*32);
  std::snprintf(buff, sizeof(buff), "%d", frc::DriverStation::GetMatchTime());
 frc::SmartDashboard::PutString(buff,"Intaking");
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
  return (m_arm->is_loaded() && m_arm->get_position() == CONSTANTS::ARM::STORE_POS);
}

