/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/DragTurn.h"

DragTurn::DragTurn(DriveTrain* pDriveTrain, double degrees, double radius, double speed): mpDriveTrain{pDriveTrain}, mDegrees{degrees}, mRadius{radius}, mSpeed{speed}  {
  // Use addRequirements() here to declare subsystem dependencies.
  //Degrees positive for right (clockwise), negative for left (counterclockwise)
  mTarget = (int) (2*radius*(degrees/360)/6);
}

// Called when the command is initially scheduled.
void DragTurn::Initialize() {
  mpDriveTrain->resetEncs();
}

// Called repeatedly when this Command is scheduled to run
void DragTurn::Execute() {
  if (mDegrees > 0) {
    mpDriveTrain->move(mSpeed, mSpeed*(mRadius/(mRadius-23)));
  }
  else {
    mpDriveTrain->move(mSpeed*(mRadius/(mRadius-23)), mSpeed);
  }
}

// Called once the command ends or is interrupted.
void DragTurn::End(bool interrupted) {
  mpDriveTrain->stop();
}

// Returns true when the command should end.
bool DragTurn::IsFinished() {
  if (mDegrees > 0) {
    return (mpDriveTrain->getLEncs() <= mTarget);
  }
  else if (mTarget > 0) {
    return (mpDriveTrain->getLEncs() >= mTarget*(mRadius/(mRadius-23)));
  }
  else {
    return(mpDriveTrain->getLEncs() <= mTarget*(mRadius/(mRadius-23)));
  }
}
