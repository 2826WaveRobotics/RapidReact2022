// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: PIDSubsystem - DRIVE

#pragma once

#include "frc2/command/PIDSubsystem.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <rev/CANSparkMax.h>
#include "AHRS.h" //navx gyroscope


/**
 * header file for the drive
 *
 * @author WAVE Robotics 2826
 */
class Drive: public frc2::PIDSubsystem {

public:

    Drive();

    void Periodic() override;
    void SimulationPeriodic() override;
    double GetMeasurement();
    void UseOutput(double output, double setpoint);

    //double TransformDriveSpeed(double speed, double targetSpeed);
    double LerpDriveSpeed(double speed, double targetSpeed, double movePercentage);
    double GetMoveInputSpeed();
    void SetMoveInputSpeed(double moveInputSpeed);
    double GetRotateInputSpeed();
    void SetRotateInputSpeed(double rotateInputSpeed);

    static constexpr const double kP = 0.1;
    static constexpr const double kI = 0.0;
    static constexpr const double kD = 0.0;
    static constexpr const double kF = 0.0;
    void arcadeDrive(double move,double rotate);

    double GetRightFrontDriveCurrent();
    double GetRightBackDriveCurrent();
    double GetLeftFrontDriveCurrent();
    double GetLeftBackDriveCurrent();

    double GetDriveEncoderPosition();
    void ResetDrivePosition(double newPosition);

    float GetAngle();
    void ZeroAngle();
    float GetAngleDeviation();

    double GetPreviousMoveSpeed();
    void SetPreviousMoveSpeed(double speed);
    double GetPreviousRotateSpeed();
    void SetPreviousRotateSpeed(double speed);

private:

    rev::CANSparkMax *m_rightFrontDrive;
    rev::CANSparkMax *m_rightBackDrive;
    frc::MotorControllerGroup *m_rightControllerGroup;

    rev::CANSparkMax *m_leftFrontDrive;
    rev::CANSparkMax *m_leftBackDrive;
    frc::MotorControllerGroup *m_leftControllerGroup;
    frc::DifferentialDrive *m_waveDrive;

    frc::Encoder m_sparkMaxEncoder{5, 6, false, frc::Encoder::k4X};
    rev::SparkMaxRelativeEncoder *m_driveEncoder;

    AHRS* m_gyro;
    //frc2::PIDController* m_turnPID;

    double m_moveInputSpeed;
    double m_rotateInputSpeed;
    double m_drivePosition;

    float m_targetAngle;

    double m_previousMoveSpeed;
    double m_previousRotateSpeed;
    
};

