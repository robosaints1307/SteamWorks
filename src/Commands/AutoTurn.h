#ifndef AutoTurn_H
#define AutoTurn_H

#include "../CommandBase.h"

class AutoTurn : public CommandBase {
private:
PIDController* pid;
public:
	AutoTurn(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

class AutoTurnPIDSource: public PIDSource {
public:
	virtual ~AutoTurnPIDSource();
	double PIDGet();
};

class AutoTurnPIDOutput: public PIDOutput {
public:
	virtual ~AutoTurnPIDOutput();
	void PIDWrite(double a);
};

#endif  // AutoTurn_H
