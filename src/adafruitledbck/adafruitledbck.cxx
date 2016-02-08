/*
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * Copyright (c) 2016 Intel Corporation.
 * Orignal written by Adafruit Industries by Limor Fried/Ladyada and licensed
 * under MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <adafruitledbck.h>

using namespace upm;

adafruitledbck::adafruitledbck(int bus, uint8_t addr)
{
    m_i2c_bus = mraa_i2c_init(bus);
    mraa_i2c_address(m_i2c_bus, addr);
    mraa_i2c_write_byte(m_i2c_bus, 0x21);
}

void adafruitledbck::setBrightness(uint8_t brightness)
{
    if (brightness > 15) brightness = 15;
    mraa_i2c_write_byte(m_i2c_bus, 0xE0 | brightness);
}

void adafruitledbck::blinkRate(uint8_t rate)
{
    if (rate > 3) rate = 0;
    mraa_i2c_write_byte(m_i2c_bus, 0x80 | 0x01 | (rate << 1));
}

void adafruitledbck::writeDisplay()
{
    return;
}

void adafruitledbck::clear()
{
    return;
}

void adafruitledbck::drawPixel(int16_t x, int16_t y, uint16_t color)
{
    return;
}
