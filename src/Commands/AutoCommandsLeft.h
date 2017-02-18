#ifndef AutoCommandsLeft_H
#define AutoCommandsLeft_H

#include "../CommandBase.h"

class AutoCommandsLeft : public CommandBase {
public:
	AutoCommandsLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCommandsLeft_H
