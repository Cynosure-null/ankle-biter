#include "subsystems/DemoSys.h"
#include "frc/smartdashboard/SmartDashboard.h"

DemoSys::DemoSys() {
frc::SmartDashboard::PutString("Init","Initing");
}

frc2::CommandPtr DemoSys::thing_one()
{
        frc::SmartDashboard::PutString("thing","thingone") ;
    return this->RunOnce(
        [&] {
            std::cout << "Arm::move() \n";
        });
}

frc2::CommandPtr DemoSys::thing_two(double x)
{
    frc::SmartDashboard::PutString("thing", "thingtwo");
    return this->RunOnce(
        [&, x] {
            std::cout << "Arm::spin() \n";
            frc::SmartDashboard::PutNumber("x",x);
        });
}

void DemoSys::Periodic() {
frc::SmartDashboard::PutString("thing", "periodic");
     //m_arm_pid.SetReference(1, rev::CANSparkMax::ControlType::kPosition);
    // m_left_arm_motor.Set(1);
    // m_left_roller_motor.Set(1);
}
