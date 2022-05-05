#include "../robotcar/Turret.h"

class TurretMock : public Turret {
	public:
		void aimRight() const override;
		void aimLeft() const override;
		void aimStraight() const override;
};
