// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: SequentialCommandGroup.

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

#include "commands/PunchAndExitTarmac.h"
#include "frc2/command/ParallelCommandGroup.h"
#include "commands/FrontPunchCommand.h"
#include "commands/BackPunchCommand.h"
#include "commands/DriveForwardTimed.h"
#include <iostream>
#include "commands/WaitCommand1.h"


PunchAndExitTarmac::PunchAndExitTarmac(Punch* punchPtr, Drive* drivePtr) {

    // Use AddRequirements() here to declare subsystem dependencies
    // eg. AddRequirements(m_Subsystem);
    SetName("PunchAndExitTarmac");
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
    
    // Add your commands here, e.g.
    // AddCommands(FooCommand(), BarCommand());
    // std::cout << "PunchAndExitTarmac - about to add FrontPunchCOmand" << std::endl;
    AddCommands(
        FrontPunchCommand(punchPtr),
        WaitCommand1(units::second_t(.75)),
        // leave tarmac
        DriveForwardTimed(units::second_t(1.5), drivePtr)
    );
}

bool PunchAndExitTarmac::RunsWhenDisabled() const {
    return false;
}