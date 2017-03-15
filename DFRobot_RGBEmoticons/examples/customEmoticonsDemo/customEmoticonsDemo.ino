/*!
 * @file customEmoticonsDemo.ino
 * @brief DFRobot's RGB Emoticons
 * @n [Get the module here](等上架后添加商品购买链接)
 * @n This example Set the volume size and play music snippet.
 * @n [Connection and Diagram](等上架后添加wiki链接)
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2017
 * @copyright	GNU Lesser General Public License
 
 * @author [YangYang](Yang.Yang@dfrobot.com)
 * @version  V1.0
 * @date  2017-1-3
 */
#include"DFRobot_RGBEmoticons.h"

#define SINGLE_BUS_PIN 		2
#define Emoticons_PIXEL	8

#define RED				1
#define GREEN			2
#define YELLOW			3
#define BLUE			4
#define PURPLE			5
#define CYAN			6
#define WHITE			7

static uint8_t Emoticons[129] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
                                 0x01, 0x11, 0x21, 0x31, 0x41, 0x51, 0x61, 0x71,
                                 0x23, 0x34, 0x45, 0x56, 0x33, 0x44, 0x55};

SoftwareSinglebus  mySingleBus(SINGLE_BUS_PIN);
DFRobot_RGBEmoticons rgb(&mySingleBus);

void setup() {
  mySingleBus.begin();
  rgb.begin();
  rgb.clearScreen();//Clear the screen
}

void loop() {
  /*
   *像素点地址寄存器，高4位代表Y坐标，低4位代表X坐标（0<=y<8,0<=x<16）
   *向该地址写入数据将选择相应坐标位置像素点
   *将自定义的表情的数据放到一个数组中 然后循环要点亮LED的次数
   *以下是展示“卜”这个表情
   */
  rgb.showCustomEmoticons(Emoticons, GREEN, 23);//parameter1:pixel; parameter2:color; parameter3:pixel summation
  delay(3000);
  rgb.clearScreen();//Clear the screen
  delay(1000);
}
