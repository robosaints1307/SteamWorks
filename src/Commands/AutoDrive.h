#ifndef AutoDrive_H
#define AutoDrive_H

#include "../CommandBase.h"

class AutoDrive : public CommandBase {
public:
	AutoDrive(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	PIDController* pid;
};

class AutoDrivePIDSource: public PIDSource {
public:
	virtual ~AutoDrivePIDSource();
	double PIDGet();
};

class AutoDrivePIDOutput: public PIDOutput {
public:
	virtual ~AutoDrivePIDOutput();
	void PIDWrite(double d);
};

#endif  // AutoDrive_H
