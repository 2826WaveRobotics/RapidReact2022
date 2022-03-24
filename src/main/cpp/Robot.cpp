// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Robot.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include "commands/SequentialPunch.h"
#include "commands/BackPunchCommand.h"
#include "commands/FrontPunchCommand.h"
#include <iostream>
#include <cameraserver/CameraServer.h>

void Robot::RobotInit() {
  m_container = RobotContainer::GetInstance();  
  m_backPunchCommand = new BackPunchCommand(&m_container->m_punch);
  m_frontPunchCommand = new FrontPunchCommand(&m_container->m_punch);
  m_sequentialPunch = new SequentialPunch(&m_container->m_punch);
  // set to avoid timeout errors
  m_container->m_drive.arcadeDrive(0, 0);  

  // sets up camera stream (and give default name)
  frc::CameraServer::StartAutomaticCapture();
  // sets up 2nd camera stream
  frc::CameraServer::StartAutomaticCapture();

  // set initial intake deploy states
  m_container->m_intake.SetDeployState(false);
  m_container->m_intake.SetOverrideState(false);

}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() 
{ 
  frc2::CommandScheduler::GetInstance().Run(); 
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {
  // reset intake deploy states
  m_container->m_intake.SetDeployState(false);
  m_container->m_intake.SetOverrideState(false);

  // set to avoid timeout errors
  m_container->m_drive.arcadeDrive(0, 0);
}

void Robot::DisabledPeriodic() {
  // set to avoid timeout errors
  m_container->m_drive.arcadeDrive(0, 0);
}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  // set to avoid timeout errors
  m_container->m_drive.arcadeDrive(0, 0);

  m_autonomousCommand = m_container->GetAutonomousCommand();
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {
  // set to avoid timeout errors
  m_container->m_drive.arcadeDrive(0, 0);
}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {    
    m_autonomousCommand = nullptr;
  }

  // set initial intake deploy states
  m_container->m_intake.SetDeployState(false);
  m_container->m_intake.SetOverrideState(false);

  // set initial grasshopper position
  m_container->m_climb.SetLeftGrasshopperStow(m_container->m_climb.GetLeftGrasshopperPosition());
  m_container->m_climb.SetRightGrasshopperStow(m_container->m_climb.GetRightGrasshopperPosition());

  // set initial grasshopper override state
  m_container->m_climb.SetGrasshopperOverrideState(false);
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {

  //////////////////  TESTING CURRENT DRAW   /////////////////////////////

  // std::cout << "ClimberRoller: " << m_container->m_climb.GetClimberRollerCurrent() << std::endl;
  // std::cout << "HookDeploy: " << m_container->m_climb.GetHookDeployCurrent() << std::endl;
  // if (m_container->m_climb.GetLeftGrasshopperDeployCurrent() > 10) 
  // {
  //   std::cout << "LeftGrasshopperDeploy current: " << m_container->m_climb.GetLeftGrasshopperDeployCurrent() << std::endl;
  // }
  // if (m_container->m_climb.GetRightGrasshopperDeployCurrent() > 10)
  // {
  // std::cout << "RightGrasshopperDeploy current: " << m_container->m_climb.GetRightGrasshopperDeployCurrent() << std::endl;
  // }

  // std::cout << "LeftGrasshopperPosition: " << m_container->m_climb.GetLeftGrasshopperPosition() << std::endl;
  // std::cout << "RightGrasshopperPosition: " << m_container->m_climb.GetRightGrasshopperPosition() << std::endl;


  // std::cout << "RightFrontDrive: " << m_container->m_drive.GetRightFrontDriveCurrent() << std::endl;
  // std::cout << "RightBackDrive: " << m_container->m_drive.GetRightBackDriveCurrent() << std::endl;
  // std::cout << "LeftFrontDrive: " << m_container->m_drive.GetLeftFrontDriveCurrent() << std::endl;
  // std::cout << "LeftBackDrive: " << m_container->m_drive.GetRightBackDriveCurrent() << std::endl;

  // std::cout << "IntakeRoller: " << m_container->m_intake.GetIntakeRollerCurrent() << std::endl;
  // std::cout << "IntakeDeploy: " << m_container->m_intake.GetIntakeDeployCurrent() << std::endl;

  // std::cout << "BackPuncher: " << m_container->m_punch.GetBackPuncherCurrent() << std::endl;
  // std::cout << "FrontPuncher: " << m_container->m_punch.GetFrontPuncherCurrent() << std::endl;

  // std::cout << "TransporterBelt: " << m_container->m_transport.GetTransporterBeltCurrent() << std::endl;
  // std::cout << "RightIndexer: " << m_container->m_transport.GetRightIndexerCurrent() << std::endl;
  // std::cout << "LeftIndexer: " << m_container->m_transport.GetLeftIndexerCurrent() << std::endl;


 ///////////////////  Transport & Indexer ////////////////////

  double transporterInput = m_container->getOperatorJS()->GetRightTriggerAxis();
  bool toggleY = m_container->getOperatorJS()->GetYButton();
  double singularTransporter = m_container->getOperatorJS()->GetLeftY();
  double singularIndexer = m_container->getOperatorJS()->GetRightY();
  double transporterSpeed = 0;
  double rightIndexerSpeed = 0;
  double leftIndexerSpeed = 0;
  if (fabs(transporterInput) >= 0.07)
  {
    // reverse transporter + indexer
    if (toggleY)
    {
      transporterSpeed = transporterInput;
      rightIndexerSpeed = -transporterInput;
      leftIndexerSpeed = -transporterInput;
    }
    // set transporter + indexer
    else
    {
      transporterSpeed = -transporterInput;
      rightIndexerSpeed = transporterInput;
      leftIndexerSpeed = transporterInput;
    }
  }
  else
  {
    // set transporter individually
    if (fabs(singularTransporter) >= 0.07)
    {
      transporterSpeed = singularTransporter;
    }
    // set indexers individually
    if (fabs(singularIndexer) >= 0.07)
    {
      leftIndexerSpeed = -singularIndexer;
      rightIndexerSpeed = -singularIndexer;
    }
  }
  m_container->m_transport.SetTransporterBeltSpeed(transporterSpeed);
  m_container->m_transport.SetIndexerSpeed(leftIndexerSpeed, rightIndexerSpeed);


//////////////////  Intake  /////////////////////////////

  double intakeRollerIn = m_container->getOperatorJS()->GetLeftTriggerAxis();
  double intakeRollerSpeed = 0;
  if (fabs(intakeRollerIn) >= 0.07) 
  {
    // reverse intake
    if (toggleY)
    {
      intakeRollerSpeed = -intakeRollerIn;
    }
    // set intake
    else
    {
      intakeRollerSpeed = intakeRollerIn;
    }
  }
  m_container->m_intake.SetIntakeRoller(intakeRollerSpeed);

  bool deployIntake = m_container->getOperatorJS()->GetRightBumper();
  bool stowIntake = m_container->getOperatorJS()->GetLeftBumper();
  bool intakeOverride = m_container->getOperatorJS()->GetStartButton();
  bool hookMode = m_container->getOperatorJS()->GetBackButton();
  bool isDeployed = m_container->m_intake.GetIntakeDeployed();
  bool deployState = m_container->m_intake.GetDeployState();
  bool overrideState = m_container->m_intake.GetOverrideState();
  double deployPosition = m_container->m_intake.GetIntakeDeployPosition();
  double intakeDeploySpeed = 0;

  // TESTING PRINTOUTS
  // if (deployState)
  // {  
  //   std::cout << "stopping condition " << fabs(deployPosition - m_container->m_intake.GetTriggeredPosition()) << std::endl; 
  // }
  
  // check NOT hook mode
  if (!hookMode)
  {
    if (intakeOverride)
    {
      m_container->m_intake.SetOverrideState(true);
    }
    // OVERRIDE state = true
    if (overrideState)
    {
      if (deployIntake)
      {
        intakeDeploySpeed = 0.5;
      }
    }
    // OVERRIDE state = false
    else
    {
      // check if sensor tripped while deploying
      if (deployIntake && isDeployed)
      {
        m_container->m_intake.SetDeployState(true);
        m_container->m_intake.SetTriggeredPosition(deployPosition);
      }
      // reset deploy state
      if (stowIntake && isDeployed)
      {
        m_container->m_intake.SetDeployState(false);
      }
      // if deploying and deploy state true
      if (deployIntake && deployState)
      {
        if (fabs(deployPosition - m_container->m_intake.GetTriggeredPosition()) < 1.2)
        {
          intakeDeploySpeed = 1.0;
        }
        else
        {
          intakeDeploySpeed = 0;   
        }
      }
      else if (deployIntake && !deployState)
      {
        intakeDeploySpeed = 1.0;
      }
    }
    // stow intake
    if (stowIntake)
    {
      intakeDeploySpeed = -1.0;
    }
  }
  m_container->m_intake.SetIntakeDeploy(intakeDeploySpeed);


//////////////////  Climber   /////////////////////////////

  double climbSpeed = m_container->getDriverJS()->GetRightTriggerAxis();
  if (fabs(climbSpeed) < 0.07)
  {
    climbSpeed = 0;
  }
  // set front and back climb motors
  m_container->m_climb.SetGrasshopperDriveSpeed(-climbSpeed);
  m_container->m_climb.SetClimberRollerSpeed(-climbSpeed);

  bool grasshopperDeploy = m_container->getDriverJS()->GetYButton();
  bool grasshopperStow = m_container->getDriverJS()->GetXButton();
  bool grasshopperStowOverride = m_container->getDriverJS()->GetBackButtonPressed();
  bool grasshopperStowOverrideReleased = m_container->getDriverJS()->GetBackButtonReleased();
  bool grasshopperOverrideState = m_container->m_climb.GetGrasshopperOverrideState();
  double rightGrasshopperDeploySpeed = 0;
  double leftGrasshopperDeploySpeed = 0;
  if (grasshopperDeploy)
  {
    leftGrasshopperDeploySpeed = 0.4;
    rightGrasshopperDeploySpeed = 0.4;
  }
  else if (grasshopperStow)
  {
    // override = true
    if (grasshopperStowOverride)
    {
        leftGrasshopperDeploySpeed = -0.3;
        rightGrasshopperDeploySpeed = -0.3;
        m_container->m_climb.SetGrasshopperOverrideState(true);
    }
    // override just released
    else if (grasshopperStowOverrideReleased && grasshopperOverrideState)
    {
      m_container->m_climb.SetLeftGrasshopperStow(m_container->m_climb.GetLeftGrasshopperPosition());
      m_container->m_climb.SetRightGrasshopperStow(m_container->m_climb.GetRightGrasshopperPosition());
      m_container->m_climb.SetGrasshopperOverrideState(false);
    }
    // override = false
    else
    {
      if (fabs(m_container->m_climb.GetLeftGrasshopperStow() - m_container->m_climb.GetLeftGrasshopperPosition()) > 0)
      {
        leftGrasshopperDeploySpeed = -0.3;
      }
      if (fabs(m_container->m_climb.GetRightGrasshopperStow() - m_container->m_climb.GetRightGrasshopperPosition()) > 0)
      {
        rightGrasshopperDeploySpeed = -0.3;
      }
    }
  }
  // set climb deploy motors
  m_container->m_climb.SetGrasshopperDeploySpeed(leftGrasshopperDeploySpeed, rightGrasshopperDeploySpeed);

  double hookDeploySpeed = 0;
  if (hookMode)
  {
    if (deployIntake)
    { 
      hookDeploySpeed = 1.0;
    }
    else if (stowIntake)
    {
      hookDeploySpeed = -1.0;
    }
  }
  // set hook deploy motor
  m_container->m_climb.SetHookDeploySpeed(hookDeploySpeed);

  //////////////////  Drive   /////////////////////////////
  
  double moveInput = m_container->getDriverJS()->GetLeftY();
  double rotateInput = m_container->getDriverJS()->GetRightX();
  double cutSpeed = m_container->getDriverJS()->GetLeftTriggerAxis();
  double moveInputSpeed = 0;
  double rotateInputSpeed = 0;
  // we are NOT climbing
  if (fabs(moveInput) >= 0.07)
  {
    moveInputSpeed = moveInput;  
  }
  if (fabs(rotateInput) >= 0.07)
  {
    rotateInputSpeed = rotateInput;
  }
  if (cutSpeed >= 0.07)
  {
    moveInputSpeed = 0.75 * moveInput;
    rotateInputSpeed = 0.75 * rotateInput;
  }
  // we ARE climbing
  if (fabs(climbSpeed) >= 0.07)
  {
    moveInputSpeed = 0.5;
    rotateInputSpeed = 0;
  }  
  // set drive motors
  m_container->m_drive.arcadeDrive(moveInputSpeed, rotateInputSpeed);

//////////////////  Puncher   /////////////////////////////

  // run the BACK punch command - X
  // aka INNER punch
  if (m_container->getOperatorJS()->GetXButton())
  {
    m_backPunchCommand->Schedule(); 
  }

  // run the FRONT punch command - B
  // aka OUTER punch
  if (m_container->getOperatorJS()->GetBButton())
  {
    m_frontPunchCommand->Schedule(); 
  }

  // run the SEQUENTIAL punch command - A
  if (m_container->getOperatorJS()->GetAButton())
  {
    m_sequentialPunch->Schedule(); 
  }

  // MANUALLY RUN PUNCHERS - currently unused
  // double punchFront = 0;
  // double punchBack = 0;
  // // MANUALLY run both punch = A
  // if(m_container->getOperatorJS()->GetAButton())
  // {
  //   punchFront = 0.8;
  //   punchBack = 0.8;
  // }
  // // MANUALLY run individual front punch = X 
  // if (m_container->getOperatorJS()->GetXButton())
  // {
  //   punchFront = 0.8;
  // }
  // // individual back punch = B
  // if (m_container->getOperatorJS()->GetBButton())
  // {
  //   punchBack = 0.8;
  // }
  // m_container->m_punch.SetFrontPuncherSpeed(punchFront);
  // m_container->m_punch.SetBackPuncherSpeed(punchBack);

} // end TeleopPeriodic

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
