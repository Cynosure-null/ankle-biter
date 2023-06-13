// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "swerve/Drivetrain.h"
#include "swerve/ngr.h"
#include "swerve/Odometry.h"
#include "swerve/SwerveModule.h"
#include "swerve/Trajectory.h"
#include "swerve/Vision.h"
#include "Buttons.h"

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc/XboxController.h>
#include "subsystems/Arm.h"

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

 private:
    // Replace with CommandPS4Controller or CommandJoystick if needed
    frc2::CommandXboxController m_driver_controller{CONSTANTS::XBOX_PORT};

    frc::XboxController m_basic_driver_controller{CONSTANTS::AUX_XBOX_PORT};

    // The robot's subsystems are defined here...

    ExampleSubsystem m_subsystem;

    Arm m_arm;

    void ConfigureBindings();

};
