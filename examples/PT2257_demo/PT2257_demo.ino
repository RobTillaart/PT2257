//
//    FILE: PT2257_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test basic behaviour and performance
//     URL: https://github.com/RobTillaart/PT2257


#include "PT2257.h"


PT2257 myPT;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("PT2257_LIB_VERSION: ");
  Serial.println(PT2257_LIB_VERSION);
  Serial.println();

  Wire.begin();
  myPT.begin();

  myPT.allOff();
}


void loop()
{

  delay(2000);
}


//  -- END OF FILE --
