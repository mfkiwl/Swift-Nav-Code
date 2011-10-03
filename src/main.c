/*
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/f2/rcc.h>
#include <libopencm3/stm32/f2/gpio.h>
#include <stdio.h>

#include "debug.h"
#include "board/leds.h"

int main(void)
{
  point pt;
  pt.x = 5;
  pt.y = 22;
  pt.foo = 0.223344;

	led_setup();
  debug_setup();

  led_on(LED_GREEN);
  led_off(LED_RED);

	/* Blink the LEDs on the board. */
	while (1) {
		/* Using API function gpio_toggle(): */
		led_toggle(LED_GREEN);
		led_toggle(LED_RED);
    printf("Hello world\n");
    DEBUG_MSG(MSG_POINT, pt);
    //DEBUG_MSG(MSG_POINT, "Hi");
		//for (i = 0; i < 600000; i++)	/* Wait a bit. */
	//		__asm__("nop");
	}

	return 0;
}