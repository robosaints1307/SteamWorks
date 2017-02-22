#ifndef AutoDrive_H
#define AutoDrive_H

#include "../CommandBase.h"

class AutoDrive : public CommandBase {
public:
	AutoDrive(double distance, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double dist;
	float speed;
};

#endif  // AutoDrive_H
