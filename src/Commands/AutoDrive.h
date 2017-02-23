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
	double dist;
};

#endif  // AutoDrive_H
