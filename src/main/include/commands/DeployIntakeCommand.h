// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Command - DEPLOY INTAKE COMMAND

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include "subsystems/Intake.h"

/**
 * header file for deploy intake command
 *
 * @author WAVE Robotics 2826
 */
class DeployIntakeCommand: public frc2::CommandHelper<frc2::CommandBase, DeployIntakeCommand> {

public:

    DeployIntakeCommand(Intake* intake);

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;
    bool RunsWhenDisabled() const override;

private:

    int phase;
    Intake* m_intake;
};
