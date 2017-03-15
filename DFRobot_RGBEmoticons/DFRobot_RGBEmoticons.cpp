/*!
 * @file DFRobot_RGBEmoticons.cpp
 * @brief DFRobot's Emoticons
 * @n This example implementation of I2C communication LCD
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2017
 * @copyright	GNU Lesser General Public License
 * @author [YangYang](Yang.Yang@dfrobot.com)
 * @version  V1.0
 * @date  2017-1-3
 */

#include "DFRobot_RGBEmoticons.h"

#define Emoticons_ADDR 0x04

DFRobot_RGBEmoticons::DFRobot_RGBEmoticons(SoftwareSinglebus *bus_)
	:bus(bus_)
{
	
}

void DFRobot_RGBEmoticons::begin()
{
	writeRegister(0x05, 0x01);
}	

void DFRobot_RGBEmoticons::clearScreen()
{
	writeRegister(0x06, 0x01);
}

void DFRobot_RGBEmoticons::setLuminance(uint8_t lmn)
{
	writeRegister(0x07, lmn);
}

void DFRobot_RGBEmoticons::setColor(uint8_t color_)
{
	color = color_;
	writeRegister(0x09, color);
}

void DFRobot_RGBEmoticons::displayEmoticons(uint8_t exp)
{
	writeRegister(0x08, exp);
}

void DFRobot_RGBEmoticons::showCustomEmoticons(uint8_t *p_data, uint8_t p_colro, uint8_t len)
{
	for(uint8_t i=0; i<len; i++){
		EmoticonsPixel(0x0A, p_data[i], p_colro);
		delay(1);
    }
	writeRegister(0x17, 0x01);
}

void DFRobot_RGBEmoticons::EmoticonsPixel(uint8_t registerAddr, uint8_t p_data, uint8_t p_colro)
{
	bus->beginTransmission(Emoticons_ADDR,WRITE);
	bus->write(registerAddr);//register address
	bus->write(p_data);//data
	delay(1);
	bus->write(p_colro);//color
	bus->endTransmission();
}

void DFRobot_RGBEmoticons::writeRegister(uint8_t registerAddr, uint8_t str)
{
	bus->beginTransmission(Emoticons_ADDR,WRITE);
	bus->write(registerAddr);//register address
	bus->write(str);//data
	bus->endTransmission();
	delay(1);
}