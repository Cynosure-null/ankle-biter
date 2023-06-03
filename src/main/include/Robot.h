// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Drivetrain.h"
#include "ngr.hpp"
#include "Odometry.h"
#include "SwerveModule.hpp"
#include "Trajectory.hpp"
#include "Vision.h"
#include "Buttons.h"

#include <optional>

#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "RobotContainer.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

  Drivetrain m_drivetrain;
  Odometry m_odometry;
 private:
  frc::SendableChooser<std::string> m_chooser;
  void swerveDrive(bool const &field_relative = true);
  // Have it empty by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  std::optional<frc2::CommandPtr> m_autonomousCommand;
  
  RobotContainer m_container;
};