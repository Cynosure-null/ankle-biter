#include "subsystems/Arm.h"

Arm::Arm() {
    m_right_arm_motor.Follow(m_left_arm_motor);
    m_right_roller_motor.Follow(m_left_roller_motor);

}

frc2::CommandPtr Arm::move(double setpoint)
{
    return this->RunOnce(
        [&, setpoint] {
            m_arm_pid.SetReference(setpoint,
                                   rev::CANSparkMax::ControlType::kSmartMotion);
        });
}

frc2::CommandPtr Arm::spin(double speed)
{
    return this->RunOnce(
        [&] {
            m_left_roller_motor.Set(speed);
        });
}

double Arm::get_position()
{
    return m_left_arm_motor.GetEncoder().GetPosition();
}

bool Arm::is_loaded()
{
    return (m_left_roller_motor.GetOutputCurrent() >
            CONSTANTS::ARM::LOADED_CURRENT);
}

void Arm::Periodic() {}

void Arm::SimulationPeriodic() {}
