#ifndef settings_h
#define settings_h

#include "Arduino.h"
#include <settings.h>



    void settings_save();
    void settings_read();
    void settings_initiateDefault();

    // Variables for settings
    extern uint8_t s_Settings_initiated; // value 111 if settings initiated at least once.
    extern  int s_KofH_pointsToWin;
    extern int s_KofH_numberOfTeams;
    extern bool s_KofH_activeTeams[4];
    extern int s_KofH_gameDuration;
    extern int s_KofH_delayedStartTime;

    // Adresses for EEPROM
    const int adr_s_Settings_initiated = 0;
    // (int has same size as 4 bytes, therefore 4 adresses are needed for each int)
    const int adr_s_KofH_pointsToWin = 1;
    const int adr_s_KofH_numberOfTeams = 5;
    const int adr_s_KofH_gameDuration = 9;
    const int adr_s_KofH_delayedStartTime = 13;
    const int adr_s_KofH_activeTeams = 17; // unknown length, is array of 4 bools.


#endif