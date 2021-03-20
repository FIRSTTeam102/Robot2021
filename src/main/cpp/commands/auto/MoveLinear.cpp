/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/MoveLinear.h"

MoveLinear::MoveLinear(DriveTrain* pDriveTrain, double target, double speed): mpDriveTrain(pDriveTrain), mTarget(target), mSpeed(speed) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pDriveTrain);
  mTargetDegs = (int) (target*60/3.1415);
}

// Called when the command is initially scheduled.
void MoveLinear::Initialize() {
  mpDriveTrain->resetEncs();
}

// Called repeatedly when this Command is scheduled to run
void MoveLinear::Execute() {
  mpDriveTrain->move(mSpeed, mSpeed);
}

// Called once the command ends or is interrupted.
void MoveLinear::End(bool interrupted) {
  mpDriveTrain->move(0, 0);
}

// Returns true when the command should end.
bool MoveLinear::IsFinished() { 
  if(mpDriveTrain->getLEncs() >= mTargetDegs){
    return true;
  }
  return false; 
  }
