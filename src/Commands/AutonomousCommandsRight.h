#ifndef AutonomousCommandsRight_H
#define AutonomousCommandsRight_H

#include <Commands/CommandGroup.h>
#include "AutoDrive.h"
#include "AutoTurn.h"

class AutonomousCommandsRight : public CommandGroup {
public:
	AutonomousCommandsRight();
};

#endif  // AutonomousCommandsRight_H
