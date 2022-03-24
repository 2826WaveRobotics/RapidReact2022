// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Command - FRONT PUNCH COMMAND

#include "commands/FrontPunchCommand.h"
#include "iostream"

/**
 * code for front punch command
 * 
 * @author WAVE Robotics 2826
 */
FrontPunchCommand::FrontPunchCommand(Punch* punch) : m_punch(punch) {
    
    // Use AddRequirements() here to declare subsystem dependencies
    // eg. AddRequirements(m_Subsystem);
    SetName("FrontPunchCommand");
}

// Called just before this Command runs the first time
void FrontPunchCommand::Initialize() 
{
    if (m_punch->GetFrontCamSensor())
    {
        phase = phase_1_inSensor;
    } 
    else 
    {
        phase = phase_2_exitSensor;
    }
}

// Called repeatedly when this Command is scheduled to run
void FrontPunchCommand::Execute() 
{
    switch(phase)
    {
        case phase_0_notRunning:
            //right when the person press punch. 
            //If the sensor is currently seen go to insensor phase.
            //if sensor is not seen go to exit sensor phase.
            if (m_punch->GetFrontCamSensor())
            {
            phase = phase_1_inSensor;
            } 
            else 
            {
                phase = phase_2_exitSensor;
            }
            break;
        case phase_1_inSensor:
            if(m_punch->GetFrontCamSensor())
            {
                //Still in the sensor area, still need to keep rotating the cam.
                phase = phase_1_inSensor;
                m_punch->SetFrontPuncherSpeed(0.75);
            }
            else
            {
                //Left the sensor area, now we need to keep rotating until we see the sensor again
                phase = phase_2_exitSensor;
            }
            //Do In Sensor stuff
            break;
        case phase_2_exitSensor:
            //Do exit sensor stuff
            if(!m_punch->GetFrontCamSensor())
            {
                //Haven't seen the sensor yet, keep the motor going
                phase = phase_2_exitSensor;
                m_punch->SetFrontPuncherSpeed(0.75);
            }
            else
            {
                //We saw the sensor, now it's time to stop
                phase = phase_3_foundSensor;
            }
            break;
        case phase_3_foundSensor:
            // Do found sensor things
            //Now that we found the sensor and stopped the cam, we need to know when 
            //someone lets go of the button.
            //Hang out here until the operator lets go of the button.
            phase = phase_3_foundSensor;
            m_punch->SetFrontPuncherSpeed(0);
            break;
        default:
            phase = phase_0_notRunning;
            break;
    }
}

// Make this return true when this Command no longer needs to run execute()
bool FrontPunchCommand::IsFinished() 
{
    if (phase == phase_3_foundSensor)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

// Called once after isFinished returns true
void FrontPunchCommand::End(bool interrupted) {
    m_punch->SetFrontPuncherSpeed(0);
}

bool FrontPunchCommand::RunsWhenDisabled() const {
    return false;
}
