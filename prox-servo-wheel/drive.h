#define DRIVING_SPEED 100
#define LEFT_WHEEL_FORWARD FORWARD
#define RIGHT_WHEEL_FORWARD BACKWARD
#define LEFT_WHEEL_BACKWARD BACKWARD
#define RIGHT_WHEEL_BACKWARD FORWARD

class Drive {
	public:
		Drive();
		void init();
		void startForward();
		void stop();
		void turnLeft();
		void turnRight();
};
