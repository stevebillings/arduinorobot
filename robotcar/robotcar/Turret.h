class Turret {
	public:
		virtual void aimRight() const = 0;
		virtual void aimLeft() const = 0;
		virtual void aimStraight() const = 0;
};
