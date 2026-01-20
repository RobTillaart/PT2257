#pragma once
//
//    FILE: PT2257.h
//  AUTHOR: Rob Tillaart
//    DATE: 2026-01-20
// VERSION: 0.1.0
// PURPOSE: Arduino library for PT2257
//     URL: https://github.com/RobTillaart/PT2257
//


#include "Arduino.h"
#include "Wire.h"


#define PT2257_LIB_VERSION         (F("0.1.0"))

//  ERROR CODES
//  values <> 0 are errors.
#define PT2257_OK                  0x00
#define PT2257_CRC_ERROR           0x01
#define PT2257_NOT_READY           0x10
#define PT2257_REQUEST_ERROR       0x11


class PT2257
{
public:
  PT2257(TwoWire *wire = &Wire);

  bool     begin();
  bool     isConnected();
  uint8_t  getAddress();


  //  Functions, datasheet p.6
  void     allOff();
  void     mute(bool mute);
  bool     isMuted();

  //  dB = 0..79
  bool     stereo(int dB);
  bool     left(int dB);
  bool     right(int dB);
  int      getLeft();
  int      getRight();

  //       DEBUG
  int      getLastError();


private:
  uint8_t  _address = 0x2A;
  TwoWire* _wire;
  int      _write(uint8_t command);

  int      _left  = 79;  //  holds absolute value
  int      _right = 79;  //  holds absolute value
  bool     _muted = false;

  uint8_t  _error;
};


//  -- END OF FILE --





