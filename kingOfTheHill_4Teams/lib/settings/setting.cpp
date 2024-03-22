#include "Arduino.h"
#include <settings.h>
#include <EEPROM.h>

// Variable definitions
uint8_t s_Settings_initiated;
int s_KofH_pointsToWin;
int s_KofH_numberOfTeams;
bool s_KofH_activeTeams[4];
int s_KofH_gameDuration;
int s_KofH_delayedStartTime;

// Read setings from EEPROM
void settings_read()
{
    EEPROM.get(adr_s_KofH_delayedStartTime, s_KofH_delayedStartTime);
    EEPROM.get(adr_s_KofH_gameDuration, s_KofH_gameDuration);
    EEPROM.get(adr_s_KofH_numberOfTeams, s_KofH_numberOfTeams);
    EEPROM.get(adr_s_KofH_pointsToWin, s_KofH_pointsToWin);
    EEPROM.get(adr_s_KofH_activeTeams, s_KofH_activeTeams);
}

// Save settings to EEPROM
void settings_save()
{
    EEPROM.put(adr_s_KofH_delayedStartTime, s_KofH_delayedStartTime);
    EEPROM.put(adr_s_KofH_gameDuration, s_KofH_gameDuration);
    EEPROM.put(adr_s_KofH_numberOfTeams, s_KofH_numberOfTeams);
    EEPROM.put(adr_s_KofH_pointsToWin, s_KofH_pointsToWin);
    EEPROM.put(adr_s_KofH_activeTeams, s_KofH_activeTeams);
}

void settings_initiateDefault()
{
    if (EEPROM.read(adr_s_Settings_initiated) != 111)
    {
        s_KofH_delayedStartTime = 60;
        s_KofH_gameDuration = 900;
        s_KofH_numberOfTeams = 4;
        s_KofH_activeTeams[0] = true;
        s_KofH_activeTeams[1] = true;
        s_KofH_activeTeams[2] = true;
        s_KofH_activeTeams[3] = true;
        s_KofH_pointsToWin = 600;
        settings_save();
        EEPROM.write(adr_s_Settings_initiated, 111);
    }
}