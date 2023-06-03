#pragma once

#include "SwerveModule.hpp"
#include "Drivetrain.h"
#include "ngr.hpp"
#include "Constants.h"
#include <iostream>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/smartdashboard/SmartDashboard.h>


#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/smartdashboard/Field2d.h>
#include <frc/geometry/Pose2d.h>
#include <frc/estimator/SwerveDrivePoseEstimator.h>
#include <TimeOfFlight.h>
#include <frc/DriverStation.h>

class Odometry
{
    public:
    Odometry();
    void putField2d();

    [[nodiscard]] frc::Pose2d getPose();

    void reset_position_from_vision(const frc::Pose2d &bot_pose);

    void reset_from_distance();

    void update();

    void resetPosition(const frc::Pose2d &pose,
                       const frc::Rotation2d &gyroAngle);

    [[nodiscard]] frc::FieldObject2d *getField2dObject(std::string_view name);

    [[nodiscard]] frc::ChassisSpeeds const getFieldRelativeSpeeds();
    private:
    Drivetrain m_drivetrain;
    
};
