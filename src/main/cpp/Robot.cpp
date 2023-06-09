// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"


#include <frc2/command/CommandScheduler.h>

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_odometry.update();
  m_drivetrain.flip();
 
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand) {
    m_autonomousCommand->Cancel();
  }
  m_odometry.update();
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

/**
 * This function is called once when the robot is first started up.
 */
void Robot::SimulationInit() {}

/**
 * This function is called periodically whilst in simulation.
 */
void Robot::SimulationPeriodic() {}


/////////////////////

/******************************************************************/
/*                        Private Variables                       */
/******************************************************************/


void Robot::RobotInit()
{
  // Call the inits for all subsystems here
  m_drivetrain.init();
  m_odometry.putField2d();

  // Auto paths

  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  m_odometry.putField2d();


  // Get choosen autonomous mode
}

  void Robot::swerveDrive(bool const &field_relative)
{
  const units::meters_per_second_t left_right { -frc::ApplyDeadband(BUTTON::DRIVETRAIN::LX(), CONSTANTS::DEADBAND)};
                          
  const units::meters_per_second_t front_back { -frc::ApplyDeadband(BUTTON::DRIVETRAIN::LY(), CONSTANTS::DEADBAND)};
  auto const rot = frc::ApplyDeadband(BUTTON::DRIVETRAIN::RX(), CONSTANTS::DEADBAND) * (CONSTANTS::DRIVE::TELEOP_MAX_ANGULAR_SPEED);

    m_drivetrain.drive(front_back, -left_right, rot, field_relative);

    // frc::SmartDashboard::PutNumber("Gyro: ", m_drivetrain.getAngle().value());
    // frc::SmartDashboard::PutNumber("front/back: ", front_back.value());
    // frc::SmartDashboard::PutNumber("left/right: ", left_right.value());


}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
