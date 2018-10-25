/**
@file readUV.ino
@brief This is a library for the FaBo UV I2C Brick.

  http://fabo.io/206.html

  Released under APACHE LICENSE, VERSION 2.0

  http://www.apache.org/licenses/

@author FaBo<info@fabo.io>
*/

#include <FaBoUV_Si1132.h>

FaBoUV faboUV;

void setup()
{
  Serial.begin(115200); // シリアルの開始デバック用
   
  Serial.println("Checking I2C device...");

  while(!faboUV.begin()){
    Serial.println("Si1132 Not Found");
    delay(5000);
  }
  
  Serial.println("I am Si1132");
  Serial.println("");
}

void loop()
{ 
  double uvindex = faboUV.readUV();
  double ir = faboUV.readIR();
  double visible = faboUV.readVisible();
  
  Serial.print("UV:");
  Serial.println(uvindex);
  Serial.print("IR:");
  Serial.println(ir);
  Serial.print("Visible:");
  Serial.println(visible);
  Serial.println("");
  
  delay(1000);
}
