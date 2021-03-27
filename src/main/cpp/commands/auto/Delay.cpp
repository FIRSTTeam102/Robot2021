/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/Delay.h"

Delay::Delay(double targ): mTarg{targ} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Delay::Initialize() {
  mTimer.Reset();
  mTimer.Start();
}

// Called repeatedly when this Command is scheduled to run
void Delay::Execute() {}

// Called once the command ends or is interrupted.
void Delay::End(bool interrupted) {
  mTimer.Stop();
}

// Returns true when the command should end.
bool Delay::IsFinished() { return mTimer.Get() > mTarg; }
