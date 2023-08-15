// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

class DemoSys : public frc2::SubsystemBase {
  public:
  DemoSys();

    frc2::CommandPtr thing_one();
 
    frc2::CommandPtr thing_two(double x);

    void Periodic() override;

    /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */

  private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // Note: The left motor will be the leader and the right will be the follower
 
};
