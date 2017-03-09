/*!
 * @file DFRobot_RGBEmoticons.h
 * @brief DFRobot's Emoticons
 * @n This example RGB Emoticons
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2017
 * @copyright	GNU Lesser General Public License
 * @author [YangYang](Yang.Yang@dfrobot.com)
 * @version  V1.0
 * @date  2017-1-3
 */


#ifndef DFRobot_RGBEmoticons_h
#define DFRobot_RGBEmoticons_h

#include <SoftwareSinglebus.h>
#include <Arduino.h>


class DFRobot_RGBEmoticons
{
public:
	/*!
	*  @brief Constructor.
	*/
	DFRobot_RGBEmoticons(SoftwareSinglebus *bus_);
	
	/*!
	*  @brief start.
	*/
	void begin();
	
	/*!
	*  @brief Clear the screen.
	*/
	void clearScreen();
	
   /*!
	*  @brief set luminance.
	*/	
	void setLuminance(uint8_t lmn);
	
	/*!
	*  @brief set color.
	*/
	void setColor(uint8_t color_);
	
	/*!
	*  @brief display Emoticons.
	*/
	void displayEmoticons(uint8_t exp);
	
	/*!
	*  @brief Write register.
	*/
	void writeRegister(uint8_t registerAddr, uint8_t str); 
	
	/*!
	*  @brief Show custom emoticons.
	*/
	void showCustomEmoticons(uint8_t *p_data, uint8_t p_colro, uint8_t len);
		
private:
	void EmoticonsPixel(uint8_t registerAddr, uint8_t data, uint8_t p_color); 
	SoftwareSinglebus *bus;///<single bus.
	uint8_t color;
};

#endif
