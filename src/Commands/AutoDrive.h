#ifndef AutoDrive_H
#define AutoDrive_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

class AutoDrive : public CommandBase {

private:
	PIDController *pid;

public:
	AutoDrive(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

class AutoMoveSource: public PIDSource{
public:
	virtual ~AutoMoveSource();
	double PIDGet();
};
class AutoMoveOutput: public PIDOutput{
public:
	virtual ~AutoMoveOutput();
	void PIDWrite(float d);
};

#endif  // AutoDrive_H
