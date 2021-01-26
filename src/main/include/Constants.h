// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

/*----------------------------------------------------------------------------*/
/* Swerve Drive Mappings                                                      */
/*----------------------------------------------------------------------------*/
#define ID_LEFT_AFT_DRIVE       1
#define ID_LEFT_FWD_DRIVE       2
#define ID_RIGHT_FWD_DRIVE      3
#define ID_RIGHT_AFT_DRIVE      0
#define ID_LEFT_AFT_STEER       5
#define ID_LEFT_FWD_STEER       7
#define ID_RIGHT_AFT_STEER      4
#define ID_RIGHT_FWD_STEER      6


/*----------------------------------------------------------------------------*/
/* Gamepad/Joystick Mappings                                                  */
/*----------------------------------------------------------------------------*/
#define ID_DRIVE_CONTROLLER     0
#define ID_MECH_CONTROLLER      1


/*----------------------------------------------------------------------------*/
/* Ramp Limiters                                                              */
/*----------------------------------------------------------------------------*/
#define RAMP_LIMIT_X            1.0
#define RAMP_LIMIT_Y            1.0
#define RAMP_LIMIT_R            1.0