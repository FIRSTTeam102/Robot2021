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
GalacticSearch::GalacticSearch(DriveTrain* pDriveTrain, Intake* pIntake, Indexer* pIndexer) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(LowerArm(pIntake, pIndexer), RaiseArm(pIntake, pIndexer));
  printf("A: %f, B: %f\n", pDriveTrain->geVoltA(), pDriveTrain->geVoltB());
  if (pDriveTrain->geVoltA() > 2.5) { //Path A
    if (pDriveTrain->geVoltB() > 2.5) { //Red
    //Setup: Inline from C3-D5 (on B1)
      AddCommands(MoveLinear(pDriveTrain, 5*12, kSpd), //Ball 1
      /*TurnDegrees(pDriveTrain, 26.6, kSpd),*/ MoveLinear(pDriveTrain, 2.24*12.0, kSpd), //Ball 2
      Delay(pDriveTrain, 500), TurnDegrees(pDriveTrain, -150, kSpd), MoveLinear(pDriveTrain, 8*12.0, kSpd), //Ball 3
      Delay(pDriveTrain, 500), TurnDegrees(pDriveTrain, 60, kSpd), MoveLinear(pDriveTrain, 15*12, kSpd)); //Finish
    }
    else { //Blue
    //Setup: Parallel to wall at E1
      AddCommands(MoveLinear(pDriveTrain, 7.5*12, kSpd), //Ball 1
      Delay(pDriveTrain, 500), TurnDegrees(pDriveTrain, -120, kSpd), MoveLinear(pDriveTrain, 8*12.0, kSpd), //Ball 2
      Delay(pDriveTrain, 500), TurnDegrees(pDriveTrain, 90, kSpd), MoveLinear(pDriveTrain, 15*12.0, kSpd)); //Ball 3 - Finish
    }
  }
  else { //Path B
    if (pDriveTrain->geVoltB() > 2.5) { //Red
    //Setup: On (A-side wall)1, inline with B3-D5
      AddCommands(MoveLinear(pDriveTrain, 8.0*12.0, kSpd), //Ball 1-2
      Delay(pDriveTrain, 500), TurnDegrees(pDriveTrain, -105, 0.7), MoveLinear(pDriveTrain, 7.07*12.0, kSpd), //Ball 3
      /*Delay(pDriveTrain, 500), TurnDegrees(pDriveTrain, 1, kSpd)*/ DragTurn(pDriveTrain, 90, 30.0, kSpd), MoveLinear(pDriveTrain, 7.5*12.0, kSpd)); //Finish
    }
    else { //Blue
    //Setup: Parallel to wall at D1
      AddCommands(MoveLinear(pDriveTrain, 8.0*12.0, kSpd), //Ball 1
      Delay(pDriveTrain, 500), TurnDegrees(pDriveTrain, -75, 0.5), MoveLinear(pDriveTrain, 7.07*12.0, kSpd), //Ball 2
      Delay(pDriveTrain, 500), TurnDegrees(pDriveTrain, 10, 0.5), MoveLinear(pDriveTrain, 10.61*12.0, kSpd)); //Ball 3 - Finish
    }
  }
}
