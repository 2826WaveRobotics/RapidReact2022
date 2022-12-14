// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Subsystem.

#include "subsystems/Vision.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "networktables/NetworkTableInstance.h"
//#include "networktables/NetworkTable.h"


// //copy
// #include "frc/smartdashboard/Smartdashboard.h"
// #include "networktables/NetworkTable.h"
// #include "networktables/NetworkTableInstance.h"
// #include "networktables/NetworkTableEntry.h"
// #include "networktables/NetworkTableValue.h"
// #include "wpi/span.h"
// //copy end

using namespace nt;

static std::shared_ptr<NetworkTable> table = NetworkTableInstance::GetDefault().GetTable("limelight");

enum
{
    Led_Maintain = 0,
    Led_Off,
    Led_Blink,
    Led_On,
};

// CODE IS NOT CURRENTLY BEING USED 
Vision::Vision(){
    SetName("Vision");
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    SetSubsystem("Vision");
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    nt::NetworkTableEntry tx = table.get()->GetEntry("tx");
    horizontalOffset = tx.GetDouble(0);

    validTarget = table.get()->GetNumber("tv",0.0);
    //horizontalOffset = table.get-> GetNumber("tx",0.0);
    verticalOffset = table.get()-> GetNumber("ty",0.0);
    targetArea = table.get()-> GetNumber("ta",0.0);
    targetSkew = table.get()-> GetNumber("ts",0.0);

}

void Vision::Periodic() {
    // Put code here to be run every loop

}

void Vision::SimulationPeriodic() {
    // This method will be called once per scheduler run when in simulation

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
// start// 
bool Vision::getValidTarget() 
{
    return validTarget;
}

double Vision::getHorizontalOffset() 
{
    return horizontalOffset;
}

double Vision::getVerticalOffset()
{
    return verticalOffset;
}

double Vision::getTargetArea()
{
    return targetArea;
}

double Vision::getTargetSkew()
{
    return targetSkew;
}

void Vision::setLED(bool on)
{
    if (on)
    {
        //table -> PutNumber("ledMode", Led_On);
    }
    else
    {
        //table -> PutNumber("ledMode", Led_Off);
    }

}

bool Vision::setPipeline(int num)
{
    return table-> PutNumber("pipeline", num);
}

int Vision::getPipeline()
{
    return table-> PutNumber("getpipe", 0);
}

void Vision::activateVisionProcessing(bool vision)
{
    table-> PutNumber("camMode", !vision);
}

double Vision::getDistance(int cameraAngle, double cameraHeight, double targetHeight)
{
    double yOffset = getVerticalOffset();
    return (targetHeight - cameraHeight) / atan(cameraAngle + yOffset);
}

