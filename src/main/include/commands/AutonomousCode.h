/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/PrepFlyWheel.h"
#include "commands/ProgressIndexer.h"
#include "commands/BackUp.h"

#include "subsystems/DriveTrain.h"
#include "subsystems/Indexer.h"
#include "subsystems/Shooter.h"
class AutonomousCode
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                  AutonomousCode> {
 public:
  AutonomousCode(DriveTrain* pDriveTrain, Indexer* pIndexer, Shooter* pShooter);
};
