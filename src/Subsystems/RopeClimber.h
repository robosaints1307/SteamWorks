#ifndef RopeClimber_H
#define RopeClimber_H

#include <Commands/Subsystem.h>

class RopeClimber : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	RopeClimber();
	void InitDefaultCommand();
};

#endif  // RopeClimber_H
