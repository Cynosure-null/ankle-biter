#ifndef ERRORSPARK_H_
#define ERRORSPARK_H_

#include <rev/CANSparkMax.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
/*
* A class that sends data to FRC web components and the console to notify when a
* Neo is stalling or having an error.
*/
class ErrorSpark
{
    public:
        ErrorSpark(rev::CANSparkMax* spark, int id);
        void run();
        /// NYI
        std::string code_to_text(uint16_t error);

    private:
        bool cout_status = true;
        bool dashboard_status = true;

        ///NYI: Errors will be implimented once I figure out bitmaps.
        bool error_status = true;

        bool stall_status = true;
        rev::CANSparkMax* m_spark;
        int m_id;
};


#endif // ERRORSPARK_H_
