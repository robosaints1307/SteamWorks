#ifndef AutonomousCommandsLeft_H
#define AutonomousCommandsLeft_H

#include <Commands/CommandGroup.h>
#include "AutoDrive.h"
#include "AutoTurn.h"

class AutonomousCommandsLeft : public CommandGroup {
public:
	AutonomousCommandsLeft();
};

#endif  // AutonomousCommandsLeft_H
