#ifndef AutonomousCommandsCenter_H
#define AutonomousCommandsCenter_H

#include <Commands/CommandGroup.h>
#include "AutoDrive.h"
#include "AutoTurn.h"

class AutonomousCommandsCenter : public CommandGroup {
public:
	AutonomousCommandsCenter();
};

#endif  // AutonomousCommandsCenter_H
