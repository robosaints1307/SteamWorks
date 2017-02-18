#ifndef AutoTurn_H
#define AutoTurn_H

#include "../CommandBase.h"

class AutoTurn : public CommandBase {
public:
	AutoTurn(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoTurn_H
