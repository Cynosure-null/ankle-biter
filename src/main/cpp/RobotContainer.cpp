// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer()
{
  m_arm.SetDefaultCommand(std::move(m_hold_mode));
  // Initialize all of your commands and subsystems here
  m_hold_mode.SetName("Hold");
  m_intake_pipeline.SetName("Intake");
  m_score_pipeline.SetName("Score");

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings()
{
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
/*  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());
  */

  // TODO: test if this toggles because im lazy

  /*frc2::Trigger([this] {
    return m_driver_controller.GetXButton();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());
  */
 //m_driver_controller.X().OnTrue(&m_example_command);
 
 /*
 frc2::JoystickButton(&m_driver_controller,
 frc::XboxController::Button::kX).WhileTrue(ExampleCommand(&m_example_subsystem).ToPtr());
*/
// m_driver_controller.X().ToggleOnTrue(
//   frc2::cmd::StartEnd([&] { m_example_command.OnMethod(); },
//     [&] { m_example_command.OffMethod(); },
//     {&m_example_subsystem}));

  m_driver_controller.LeftBumper().ToggleOnTrue(&m_intake_pipeline);

  m_driver_controller.RightBumper().ToggleOnTrue(&m_score_pipeline);

  m_driver_controller.B().ToggleOnTrue(&m_hold_mode);
  

  //m_aux_controller.B().ToggleOnTrue(&m_manual);

  //m_aux_controller.X().ToggleOnTrue(&m_hold_mode);
}


frc2::CommandPtr RobotContainer::GetAutonomousCommand()
{
  // An example command will be run in autonomous
  //return autos::ExampleAuto(&m_subsystem);
}
