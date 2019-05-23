#include <IRremote.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include "Else.h"

//Timer Stuff
unsigned long previousMillis_LCD = 0;    // Variable to track LCD Timings
unsigned long previousMillis_Garden = 0; // Variable to track Garden (Valves / sensors) Timings

// Idle Graphics
int tab = 0; // Integer that holds the current idle screen

void setup()
{
    pinMode(relay_bed1, OUTPUT); // Set *relay_bed1* as an output pin (3v -> 5v)
    pinMode(relay_bed2, OUTPUT); // Set *relay_bed2* as an output pin (3v -> 5v)
    pinMode(relay_bed3, OUTPUT); // Set *relay_bed3* as an output pin (3v -> 5v)
    pinMode(relay_bed4, OUTPUT); // Set *relay_bed4* as an output pin (3v -> 5v)

    digitalWrite(relay_bed1, HIGH); // Send a 5v signal to *relay_bed1*
    digitalWrite(relay_bed2, HIGH); // Send a 5v signal to *relay_bed2*
    digitalWrite(relay_bed3, HIGH); // Send a 5v signal to *relay_bed3*
    digitalWrite(relay_bed4, HIGH); // Send a 5v signal to *relay_bed4*

    lcd.createChar(1, Moisture);    // Make an LCD icon for *Moisture*
    lcd.createChar(2, Brightness);  // Make an LCD icon for *Brightness*
    lcd.createChar(3, Temperature); // Make an LCD icon for *Temperature*

    irrecv.enableIRIn(); // Start IR Sensor
    lcd.begin(16, 2);    // Start LCD display with 16 characters, 2 lines
    lcd.clear();         // Clear the LCD display
}

void loop()
{
    unsigned long currentMillis = millis(); // Make a variable hold the current time ( 1 = 1/1000 of a second)

    if (currentMillis - previousMillis_LCD >= lcd_graphic_change_interval) // If the timer reaches the threshold
    {
        previousMillis_LCD = currentMillis;
        lcd.clear();

        if (tab == 0)
        {
            //        ================ <- maximum characters
            lcd.print("Welcome To HOMS");
            lcd.setCursor(0, 1);
            lcd.print("Garden Assistant");
        }
        if (tab == 1)
            //        ================ <- maximum characters
            lcd.print("Garden Bed 1");
        if (tab == 2)
            lcd.print("Garden Bed 2");
        if (tab == 3)
            lcd.print("Garden Bed 3");
        if (tab == 4)
            lcd.print("Garden Bed 4");
        if (!tab == 0)
        {
            lcd.setCursor(0, 1);
            lcd.write(1);
            lcd.print(getSensorData(1, tab));
            lcd.print(" ");
            lcd.write(2);
            lcd.print(getSensorData(2, tab));
            lcd.print(" ");
            lcd.write(3);
            lcd.print(getSensorData(3, tab));
        }
        if (tab == 5)
            tab = 0;
        else
            tab++;
    }

    if (currentMillis - previousMillis_Garden >= garden_check_interval) // If the timer reaches the threshold
    {
        previousMillis_Garden = currentMillis;
        //code for garden errands
        for (int i = 1; i < 4; i++)
        {
            lcd.clear();
            //        ================ <- maximum characters
            lcd.print("Checking Bed #");
            lcd.print(i);
            lcd.setCursor(0, 1);
            lcd.print("Reading: ");
            lcd.write(1);
            lcd.print(getSensorData(1, i));

            if (getSensorData(1, i) > too_dry)
            {
                waterBed(i);
            }
        }
    }

    if (irrecv.decode(&results)) // Detect input
    {
        getKey(results.value, false);
        irrecv.resume();
        delay(250);
    }

    if (keyCode == Pwr)
    {
        keyCode = Null;
        lcd.clear();
        //        ================ <- maximum characters
        lcd.print("Go into low");
        lcd.setCursor(0, 1);
        lcd.print("power mode?");

        while (1)
        {
            getKey(0, true);

            if (keyCode == Nm1)
            {
                lcd.noDisplay();
                getKey(0, true);
                break
            }
            if (keyCode == Nm0)
            {
                break;
            }
        }
    }
}
