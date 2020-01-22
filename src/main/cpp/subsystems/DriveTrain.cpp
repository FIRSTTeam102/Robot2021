/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "RobotContainer.h"
#include "Constants.h"


DriveTrain::DriveTrain():
    driveLeft1{1}, 
    driveLeft2{2}, 
    driveRight1{3}, 
    driveRight2{4}
 {

}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {



}

void DriveTrain::driveWithXboxController(){
    
    double leftSpeed = p_driverJoystick->GetRawAxis(1);
    double rightSpeed = p_driverJoystick->GetRawAxis(5);
    
    Drive.TankDrive(leftSpeed,rightSpeed,true);
    printf("%f, %f", leftSpeed, rightSpeed);

}