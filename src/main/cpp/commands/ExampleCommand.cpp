// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ExampleCommand.h"
#include <iostream>

ExampleCommand::ExampleCommand(ExampleSubsystem* subsystem)
    : m_subsystem{subsystem} {
  // Register that this command requires the subsystem.
  AddRequirements(m_subsystem);
}

bool ExampleCommand::Initalize()
{
  i = 0;
  frc::SmartDashboard::PutNumber("Init Count", j);
  j++;
}

void ExampleCommand::Execute()
{
  std::cout << "here\n";
  frc::SmartDashboard::PutNumber("Cycle:", i);
  i++;
}

bool ExampleCommand::End()
{
  i = 0;
  frc::SmartDashboard::PutNumber("End Count", k);
  k++;
}
