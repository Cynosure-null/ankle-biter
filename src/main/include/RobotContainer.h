// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#ifndef CFG_NO_DRIVEBASE

#include "swerve/Drivetrain.h"
#include "swerve/Odometry.h"
#include "swerve/SwerveModule.h"
#include "swerve/Trajectory.h"
#include "swerve/Vision.h"
#include "swerve/ngr.h"

#endif

#include <utility>
#include "commands/HoldMode.h"
#include "commands/IntakePipeline.h"
#include "commands/ScorePipeline.h"
#include "commands/Manual.h"

#include "Buttons.h"
#include "commands/ExampleCommand.h"

#include "subsystems/Arm.h"
#include <frc/XboxController.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/button/JoystickButton.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DemoSys.h"
#include <frc2/command/StartEndCommand.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including
 * subsystems, commands, and trigger mappings) should be declared here.
 */
class RobotContainer
{
public:
  RobotContainer();
        //Public so it can be manualy called in Robot.cpp
        frc2::CommandXboxController m_driver_controller{CONSTANTS::XBOX_PORT};

        frc2::CommandPtr GetAutonomousCommand();


    private:
        // Replace with CommandPS4Controller or CommandJoystick if needed

        //frc2::CommandXboxController m_aux_controller {CONSTANTS::AUX_XBOX_PORT};

        /// This is stupid, delete this. CommandXboxController inherits XboxController
        frc::XboxController m_basic_driver_controller{ CONSTANTS::AUX_XBOX_PORT };

        // The robot's subsystems are defined here...

        ExampleSubsystem m_example_subsystem;

        ExampleCommand m_example_command {&m_example_subsystem};

        Arm m_arm;

        Manual m_manual {&m_arm, &m_driver_controller};

        HoldMode m_hold_mode {&m_arm};

        IntakePipeline m_intake_pipeline {&m_arm};

        ScorePipeline m_score_pipeline {&m_arm};

        void ConfigureBindings();
};
