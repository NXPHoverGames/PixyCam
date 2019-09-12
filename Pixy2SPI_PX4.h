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
#include <drivers/device/spi.h>
#include "board_config.h"

#define PIXY_SPI_CLOCKRATE       2000000

class PIXY2_SPI: public device::SPI
{
public:
	PIXY2_SPI();
	virtual ~PIXY2_SPI() = default;

	bool is_external();
	int init();

	int8_t open(uint32_t arg)
	{
		return 0;
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

		transfer(nullptr, buf, len);

		for (i = 0; i < len; i++) {

			if (cs) {
				*cs += buf[i];
			}
		}

		return len;
	}

	int16_t send(uint8_t *buf, uint8_t len)
	{

		transfer(buf, nullptr, len);

		return len;
	}

private:
	bool _external;
};

PIXY2_SPI::PIXY2_SPI() :
	SPI("PIXY2_SPI", nullptr, PX4_SPI_BUS_EXTERNAL, PX4_SPIDEV_EXTERNAL1, SPIDEV_MODE3, PIXY_SPI_CLOCKRATE)
{
	_external = true;
}

bool PIXY2_SPI::is_external()
{
	return _external;
};

int PIXY2_SPI::init()
{
	return SPI::init();
};


typedef TPixy2<PIXY2_SPI> Pixy2;

#endif