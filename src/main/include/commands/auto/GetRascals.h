/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/auto/MoveLinear.h"
#include "commands/auto/TurnDegrees.h"
#include "commands/powercell/RaiseArm.h"
#include "commands/powercell/LowerArm.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Indexer.h"
class GetRascals //The balls are the rascals
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 GetRascals> {
 public:
  GetRascals(DriveTrain* pDriveTrain, Intake* pIntake, Indexer* pIndexer);
};
