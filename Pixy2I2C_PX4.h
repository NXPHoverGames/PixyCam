//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// Arduino ICSP SPI link class

#ifndef _PIXY2_H
#define _PIXY2_H

#include "TPixy2.h"
#include <drivers/device/i2c.h>
#include "board_config.h"

#define IRLOCK_I2C_BUS			PX4_I2C_BUS_EXPANSION
#define IRLOCK_I2C_ADDRESS		0x54 /** 7-bit address (non shifted) **/

#define IRLOCK0_DEVICE_PATH		"/dev/Pixy2"

class PIXY2_I2C: public device::I2C
{
public:
	PIXY2_I2C();
	virtual ~PIXY2_I2C() = default;

	bool is_external();
	int init();

	int8_t open(uint32_t arg)
	{
		return I2C::init();;
	}

	void close()
	{
		;
	}

	int16_t recv(uint8_t *buf, uint8_t len, uint16_t *cs = NULL)
	{
		uint8_t i;

		if (cs) {
			*cs = 0;
		}

		transfer(nullptr, 0, &buf[0], len);

		for (i = 0; i < len; i++) {

			if (cs) {
				*cs += buf[i];
			}
		}

		return len;
	}

	int16_t send(uint8_t *buf, uint8_t len)
	{

		transfer(&buf[0], len, nullptr, 0);
		//int ret_tran = transfer(&buf[0], len, nullptr, 0);
		//printf("ret_tran = %i\n", ret_tran);

		return len;
	}

private:
	bool _external;
};

PIXY2_I2C::PIXY2_I2C() :
	I2C("PIXY2_I2C", IRLOCK0_DEVICE_PATH, PX4_I2C_BUS_EXPANSION, IRLOCK_I2C_ADDRESS, 400000)
{
	_external = true;
}

bool PIXY2_I2C::is_external()
{
	return _external;
};

int PIXY2_I2C::init()
{
	return I2C::init();
};


typedef TPixy2<PIXY2_I2C> Pixy2;

#endif