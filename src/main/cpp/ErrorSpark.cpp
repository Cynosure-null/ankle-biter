#include "ErrorSpark.h"

ErrorSpark::ErrorSpark(rev::CANSparkMax* spark, int id)
    : m_spark{spark}
{
    m_id = id;
}

void ErrorSpark::run()
{
    using std::cout;
    using std::endl;

    if (stall_status &&
        cout_status &&
        m_spark->GetFault(rev::CANSparkMax::FaultID::kStall))
    {
        cout << "Neo " << m_id << " stalling!!" << endl;
    }
    if (stall_status &&
        dashboard_status &&
        m_spark->GetFault(rev::CANSparkMax::FaultID::kStall))
    {
        frc::SmartDashboard::PutBoolean("is_stalling_id"+m_id, true);
    }
}
