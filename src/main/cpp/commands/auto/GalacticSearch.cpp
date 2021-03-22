/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/GalacticSearch.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
GalacticSearch::GalacticSearch(DriveTrain* pDriveTrain) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  if (mChannelA.GetVoltage() > 2.5) { //Path A
    if (mChannelB.GetVoltage() > 2.5) { //Red
    //Setup: Inline from C3-D5 (on B1)
      AddCommands(MoveLinear(pDriveTrain, 5*12, kSpd), /*TurnDegrees(pDriveTrain, 26.6, kSpd),*/ MoveLinear(pDriveTrain, 2.24*12.0, kSpd), TurnDegrees(pDriveTrain, -98.2, kSpd), MoveLinear(pDriveTrain, 3.16*12.0, kSpd), TurnDegrees(pDriveTrain, 71.6, kSpd), MoveLinear(pDriveTrain, 15*12, kSpd));
    }
    else { //Blue
    //Setup: Parallel to wall at E1
      AddCommands(MoveLinear(pDriveTrain, 12.5*12, kSpd), TurnDegrees(pDriveTrain, -71.6, kSpd), MoveLinear(pDriveTrain, 3.16*12.0, kSpd), TurnDegrees(pDriveTrain, 91.2, kSpd), MoveLinear(pDriveTrain, 2.24*12.0*2+5, kSpd));
    }
  }
  else { //Path B
    if (mChannelB.GetVoltage() > 2.5) { //Red
    //Setup: On (A-side wall)1, inline with B3-D5
      AddCommands(MoveLinear(pDriveTrain, 14.14*12.0, kSpd), TurnDegrees(pDriveTrain, -90, kSpd), MoveLinear(pDriveTrain, 7.07*12.0, kSpd), TurnDegrees(pDriveTrain, 45, kSpd), MoveLinear(pDriveTrain, 12.5*12.0, kSpd));
    }
    else { //Blue
    //Setup: Parallel to wall at D1
      AddCommands(MoveLinear(pDriveTrain, 12.5*12.0, kSpd), TurnDegrees(pDriveTrain, -45, kSpd), MoveLinear(pDriveTrain, 7.07*12.0, kSpd), TurnDegrees(pDriveTrain, 90, kSpd), MoveLinear(pDriveTrain, 10.61*12.0, kSpd));
    }
  }
}
