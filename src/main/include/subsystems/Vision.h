// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Subsystem - VISION

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/Smartdashboard.h>

/**
 * header file for the camera (limelight)
 *
 * @author WAVE Robotics 2826
 */
class Vision: public frc2::SubsystemBase {

public:

    Vision();

    void Periodic() override;
    void SimulationPeriodic() override;

    void updateLimeLight();
    bool getValidTarget();
    double getHorizontalOffset();
    double getVerticalOffset();
    double getTargetArea();
    double getTargetSkew();
    void setLED(bool on);
    bool setPipeline(int num);
    int getPipeline();
    void activateVisionProcessing(bool vision);
    double getDistance(int cameraAngle, double cameraHeight, double targetHeight);

    bool validTarget;
    double horizontalOffset;
    double verticalOffset;
    double targetArea;
    double targetSkew;

    void SetClimbCameraState(bool state);
    bool GetClimbCameraState();

private:

    bool m_climbCameraState;

};

