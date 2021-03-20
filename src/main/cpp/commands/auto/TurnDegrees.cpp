/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/TurnDegrees.h"

TurnDegrees::TurnDegrees(DriveTrain* pDriveTrain, double degrees, double speed): mpDriveTrain{pDriveTrain}, mDegrees{degrees}, mSpeed{speed} {
  // Use addRequirements() here to declare subsystem dependencies.
  //Degrees positive for right, negative for left
  mTarget = (int) (degrees/360*3.1415*23);
}

// Called when the command is initially scheduled.
void TurnDegrees::Initialize() {
  mpDriveTrain->resetEncs();
}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {
  if (mDegrees > 0) {
    mpDriveTrain->move(mSpeed, -mSpeed);
  }
  else {
    mpDriveTrain->move(-mSpeed, mSpeed);
  }
}

// Called once the command ends or is interrupted.
void TurnDegrees::End(bool interrupted) {
  mpDriveTrain->stop();
}

// Returns true when the command should end.
bool TurnDegrees::IsFinished() {
  if (mDegrees > 0) {
    return (mpDriveTrain->getLEncs() <= mDegrees);
  }
  else {
    return (mpDriveTrain->getLEncs() >= mDegrees);
  }
}
