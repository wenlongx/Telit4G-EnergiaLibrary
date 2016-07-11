/*
 * Copyright (c) 2010 by Wenlong Xiong <wenlongx@ucla.edu>
 * 4G/LTE Library for Telit LE910SV module and Energia.
 *
 * This library is adapted from the GSM Arduino library provided by
 * Justin Downs (2010) at
 * http://wiki.groundlab.cc/doku.php?id=gsm_arduino_library
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */


#ifndef LTE_LTEBASE_H_
#define LTE_LTEBASE_H_

#include <stdlib.h>
#include <string.h>

#include <Energia.h>

// Defines general interface for objects that communicate over LTE.
class LTEBase {
  public:
    // Basic setup
    virtual LTEBase(Serial& telitPort, Serial* debugPort);
    virtual ~LTEBase() {};
    virtual bool init();

    // Only used if you turn on the Telit module using the LaunchPad
    virtual bool turnOn();
    virtual bool turnOff();

    // Telit communication
    virtual void sendATCommand(const char*);
    virtual bool receiveData(uint16_t dataSize, uint32_t timeout = 180000, uint32_t baudDelay);

    // Basic information about Telit module
    bool isRegistered();  /* Check registration status */
    const char* getSN();  /* Gets the serial number */

  protected:
    typedef HardwareSerial Serial;
    Serial& telitPort;
    Serial* debugPort;
}

#endif