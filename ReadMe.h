/*\
    The HOMS arduino-powered garden is an open project (for now)
    that promotes creativity, problem solving, and teamwork for 
    the next generation.
    
    The HOMS Robotics Team :
    = Coders:
    Riley Eisel (Main)
    Owen Ambrose (Apprentice)
    Gavin Gabel (Apprentice)

    = Engineers (3D Design) :
    Connor Garcia 
    Emmy Lee 
    Meghan Johns

    = Engineers (Structural Design / Water Distribution) :
    Olivia Heizer
    

    Created: 5/17/2019
    Last Revision: 5/17/2019 11:05AM

    This code is in the public domain.
    No licence
\*/

/* - - -  Adjust these variables ONLY!!  - - - */

// Data saving settings
bool overwriteOldSave = true; // if on, the saved data will overwrite old data when EEPROM is full

// Sensor trial settings
const int number_of_trials = 5;   // # of trials
int trial_data[number_of_trials]; // Where temporary data is stored
int delay_between_trials = 1500;  // Delay between a trial

// Sensor thresholds
int too_wet = 300;          // 300 > x | too much moisture
int perfect_moisture = 350; // 350 +-50 | 300 < x &&
int too_dry = 450;

// Bed wetting system!
int length_of_burst = 5000; // 5 seconds
int length_of_rest = 10000; // 10 seconds

int garden_check_interval = 3600000;    // 1 hour
int lcd_graphic_change_interval = 5000; // 5 seconds
/* - - -             End                 - - - */

// Moisture sensor pins
#define moisture_bed1 A1 // Analog 1
#define moisture_bed2 A2 // Analog 2
#define moisture_bed3 A3 // Analog 3
#define moisture_bed4 A4 // Analog 4

// Light level sensors
#define light_bed1 A9  // Analog 9
#define light_bed2 A10 // Analog 10
#define light_bed3 A11 // Analog 11
#define light_bed4 A12 // Analog 12

// Temperature sensor pins
#define temperature_bed1 A5 // Analog 5
#define temperature_bed2 A6 // Analog 6
#define temperature_bed3 A7 // Analog 7
#define temperature_bed4 A8 // Analog 8

// Utilities
#define relay_bed1 34 // Digital 34
#define relay_bed2 35 // Digital 35
#define relay_bed3 36 // Digital 36
#define relay_bed4 37 // Digital 37

#define ir_sensor 23 // Digital 23

// Library variables
// IR remote
IRrecv irrecv(ir_sensor);
IRsend irsend;
decode_results results;

// LCD display
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// LCD characters
byte Temperature[8] = {
    0b01110,
    0b01010,
    0b01010,
    0b01010,
    0b10001,
    0b10001,
    0b01110,
    0b00000};
byte Moisture[8] = {
    0b00100,
    0b00100,
    0b01010,
    0b01010,
    0b10001,
    0b10001,
    0b01110,
    0b00000};
byte Brightness[8] = {
    0b10101,
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
    0b10101,
    0b00000};
