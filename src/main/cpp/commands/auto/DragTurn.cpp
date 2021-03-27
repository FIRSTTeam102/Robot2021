/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/DragTurn.h"

DragTurn::DragTurn(DriveTrain* pDriveTrain, double degrees, double radius, double speed): mpDriveTrain{pDriveTrain}, mDegrees{degrees}, mRadius{radius+(23/2)}, mSpeed{speed}  {
  // Use addRequirements() here to declare subsystem dependencies.
  //Degrees positive for right (clockwise), negative for left (counterclockwise)
  AddRequirements(pDriveTrain);
  mTarget = (int) fabs((2.0*(radius+11.5)*degrees/6.0));
  printf("Drag Targ: %d", mTarget);
  slowMult = ((mRadius-11.5)-23)/(mRadius-11.5);
}

// Called when the command is initially scheduled.
void DragTurn::Initialize() {
  mpDriveTrain->resetEncs();
}

// Called repeatedly when this Command is scheduled to run
void DragTurn::Execute() {
  printf("Drag Targ: %d", mTarget);
  if (mDegrees > 0) {
    mpDriveTrain->move(mSpeed, mSpeed*slowMult);
  }
  else {
    mpDriveTrain->move(mSpeed*slowMult, mSpeed);
  }
}

// Called once the command ends or is interrupted.
void DragTurn::End(bool interrupted) {
  mpDriveTrain->stop();
}

// Returns true when the command should end.
bool DragTurn::IsFinished() {
  if (mDegrees < 0) {
    if (mSpeed > 0) {
      return (mpDriveTrain->getREncs() >= mTarget);
    }
    else {
      return (mpDriveTrain->getREncs() <= -mTarget);
    }
  }
  else if (mRadius < 23) {
    if (mSpeed > 0) {
      return (mpDriveTrain->getREncs() <= -mTarget*slowMult);
    }
    else {
      return (mpDriveTrain->getREncs() >= mTarget*slowMult);
    }
  }
  else {
    if (mSpeed > 0) {
      return(mpDriveTrain->getREncs() >= mTarget*slowMult*2.1);
    }
    else {
      return(mpDriveTrain->getREncs() <= -mTarget*slowMult);
    }
  }
  return false;
}
