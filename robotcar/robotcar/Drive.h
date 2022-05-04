class Drive {
	public:
		virtual void startForward() const = 0;
		virtual void pause() const = 0;
		virtual void stop() const = 0;
		virtual void turnLeft() const = 0;
		virtual void turnRight() const = 0;
    		virtual void turnAround() const = 0;
	        virtual void backUpALittle() const = 0;
};
