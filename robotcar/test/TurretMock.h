#include "../robotcar/Turret.h"

class TurretMock : public Turret {
	public:
		void aimRight() override;
		void aimLeft() override;
		void aimStraight() override;
};
