#ifndef AutoCommandsRight_H
#define AutoCommandsRight_H

#include "../CommandBase.h"

class AutoCommandsRight : public CommandBase {
public:
	AutoCommandsRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCommandsRight_H
