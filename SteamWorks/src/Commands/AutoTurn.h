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
private:
	PIDController* pid;
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
