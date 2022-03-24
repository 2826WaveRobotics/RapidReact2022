// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Subsystem - INTAKE

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <rev/CANSparkMax.h>

enum{
    phase_0_stowed,
    phase_1_beforeSensor,
    phase_2_inSensor,
    phase_3_afterSensor,
    phase_4_fullyDeployed
};

/**
 * header file for the intake
 *
 * @author WAVE Robotics 2826
 */
class Intake: public frc2::SubsystemBase {

public:

    Intake();

    void Periodic() override;
    void SimulationPeriodic() override;

    void SetIntakeRoller(double speed);
    void SetIntakeDeploy(double speed);

    bool GetIntakeStowed();
    bool GetIntakeDeployed();

    double GetIntakeRollerCurrent();
    double GetIntakeDeployCurrent();

    double GetIntakeDeployPosition();

    bool GetDeployState();
    void SetDeployState(bool state);

    bool GetOverrideState();
    void SetOverrideState(bool state);

    double GetTriggeredPosition();
    void SetTriggeredPosition(double position);

    private:
    // It's desirable that everything possible is private except
    // for methods that implement subsystem capabilities
    frc::DigitalInput *m_isIntakeStowed;
    frc::DigitalInput *m_isIntakeDeployed;
    rev::CANSparkMax *m_intakeRoller;
    rev::CANSparkMax *m_intakeDeploy;
    rev::SparkMaxRelativeEncoder *m_intakeDeployEncoder;

    bool m_deployState;
    bool m_overrideState;
    double m_triggeredPosition;
};

