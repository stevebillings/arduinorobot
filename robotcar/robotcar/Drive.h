class Drive {
	public:
		virtual void startForward() = 0;
		virtual void pause() = 0;
		virtual void stop() = 0;
		virtual void turnLeft() = 0;
		virtual void turnRight() = 0;
    		virtual void turnAround() = 0;
	        virtual void backUpALittle() = 0;
};
