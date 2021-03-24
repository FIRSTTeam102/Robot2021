/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoNav.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AutoNav::AutoNav(DriveTrain* pDriveTrain, int path) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  if (path == 1) { //Start on C1
    AddCommands(MoveLinear(pDriveTrain, 10*12, kSpd), DragTurn(pDriveTrain, 360, 2.5*12.0, kSpd), MoveLinear(pDriveTrain, 7.5*12.0, kSpd), DragTurn(pDriveTrain, -315, 2.5*12.0, kSpd), MoveLinear(pDriveTrain, 14.1*12.0, kSpd), DragTurn(pDriveTrain, -225, 2.5*12.0, kSpd), MoveLinear(pDriveTrain, 22.5*12.0, kSpd));
  }
  else if (path == 2) { //Start on F1
    AddCommands(DragTurn(pDriveTrain, -45, 2.92*12.0, kSpd), DragTurn(pDriveTrain, 90, 10.6*12.0, kSpd), MoveLinear(pDriveTrain, 2.5*12.0, kSpd), DragTurn(pDriveTrain, -270, 2.5*12.0, kSpd), MoveLinear(pDriveTrain, 2.5*12.0, kSpd), DragTurn(pDriveTrain, 90, 10.6*12.0, kSpd), DragTurn(pDriveTrain, -45, 2.92*12.0, kSpd));
  }
  else if (path == 3) { //Start on C1
    AddCommands(MoveLinear(pDriveTrain, 2.5*12.0, kSpd), DragTurn(pDriveTrain, 90, 2.5*12.0, kSpd), MoveLinear(pDriveTrain, 2.5*12.0, kSpd), MoveLinear(pDriveTrain, -2.5*12.0, -kSpd), DragTurn(pDriveTrain, 30, 2.5*12.0, -kSpd), MoveLinear(pDriveTrain, -3.6*12.0, -kSpd), DragTurn(pDriveTrain, 150, 2.5*12.0, -kSpd), MoveLinear(pDriveTrain, -7.5*12.0, -kSpd), MoveLinear(pDriveTrain, 7.5*12.0, kSpd), DragTurn(pDriveTrain, 90, 2.5*12.0, kSpd), MoveLinear(pDriveTrain, 2.5*12.0, kSpd), DragTurn(pDriveTrain, 90, 2.5*12.0, kSpd), MoveLinear(pDriveTrain, 7.5*12.0, kSpd), DragTurn(pDriveTrain, 90, 5*12, -kSpd));
  }
  else if (path == 0) { //Test functions
    AddCommands(MoveLinear(pDriveTrain, 2.5*12.0, kSpd), TurnDegrees(pDriveTrain, 180, kSpd));
  }
  else {
    printf("Invalid path\n");
  }
}
