/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc/AnalogInput.h>
#include <subsystems/DriveTrain.h>
#include <commands/auto/TurnDegrees.h>
#include <commands/auto/MoveLinear.h>

class GalacticSearch
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 GalacticSearch> {
 public:
  GalacticSearch(DriveTrain* pDriveTrain);
 private:
  frc::AnalogInput mChannelA{0};
  frc::AnalogInput mChannelB{1};
  double kSpd = 0.5;
};
